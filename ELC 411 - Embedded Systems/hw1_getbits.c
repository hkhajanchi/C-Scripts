#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



/* To get the desired range of bits from a 32-bit unsigned integer, I am going to use bitwise left-shifts and right-shifts.

if 0x12345678 is a 32-bit hex integer, and I wanted to extract 0x67 from it, I would first highlight the left and right indices that 0x67 corresponds to.

I would then shift 0x12345678 all the way to the left in a way that gets rid of the preceding hex integers.

To illustrate --> 0x12345678 would become 0x67800000 after being left-shifted.

I now need to get rid of the 0x800000 that follows the 0x67. To accomplish this, I will right-shift the integer 0x67800000 to the right in a way that eliminates 0x800000.

0x67800000 --> 0x67

*/


uint32_t get_bits (uint32_t reg_val,int left_idx, int right_idx)
{
  uint32_t new_val;

  reg_val = reg_val << (31 - left_idx); //Shifts the desired bit range all the way to the left
  reg_val = reg_val >> (31 - (left_idx - right_idx)); //Shifts the bit range all the way to the right to get rid of the values at the end of the bit range

  new_val = reg_val; //Stores the shifted value into a new variable

  return new_val;

}

int main ()
{
  uint32_t test_int = 0x12345678; //Test Values, should return 0x67
  uint32_t return_val = 0;
  int left_idx = 11;
  int right_idx = 4;

  return_val = get_bits(test_int,left_idx,right_idx);
  printf("%X",return_val);



}
