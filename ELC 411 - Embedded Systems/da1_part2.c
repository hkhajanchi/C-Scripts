#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define TRUE 1; //Macros for boolean TRUE and FALSE
#define FALSE 0;

//Module to get the length of the string
//Gets a pointer value for the array, iterates up to the NULL termination space in the string, and updates the value of a counter

uint32_t getLength (char *str)

{
    uint32_t strLength;

    for (strLength = 0; *str != '\0'; str ++)
        strLength++;

    return strLength;
}

//This module implements a bubble sort algorithm on the string
//On each iteration, the algorithm sorts values in the array based on the current and previous indices of the string and swaps them accordingly
//When the string is fully sorted, the algorithm exits the loop

void swapped (char *str_pointer, uint32_t stringLength)
{

  uint8_t swapped = 0; //Boolean value that goes FALSE when the algorithm is finished sorting
  uint8_t i = 0;
  char *str_pointer_next = 0;
  char temp;
  char * str_pointer_hold = str_pointer; //Holds the initial address of the first character in the string, acts as a reset for the pointer iteration

  do
  {
      swapped = FALSE;
      str_pointer = str_pointer_hold; //Resets the pointer to point back to the beginning of the string

      for (i = 1; i < (stringLength); i++) //Iterating MATLAB style
      {
          str_pointer_next = str_pointer + 1; //Points to the next character in the array

          if (*str_pointer > *str_pointer_next) //Compares string[i] and string[i + 1]
          {
              temp = *str_pointer;              //Swaps the characters if the value of the next index is higher than the previous index
              *str_pointer = *str_pointer_next;
              *str_pointer_next = temp;
              swapped = TRUE;
          }

          str_pointer++; //Sets the str_pointer to point to the next character in the array

      }

  } while (swapped);

}


int main()
{
    char myname[] = "Hussain Khajanchi"; //Test String, should result in " HKaaachhiijnnssu"

    uint32_t stringLength = 0;
    stringLength = getLength(myname);
    swapped(myname,stringLength);
    printf(myname);
}
