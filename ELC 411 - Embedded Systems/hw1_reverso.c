#include <stdio.h>
#include <stdint.h>

void reverso (char *str)
{
    //Variable Definitions
    int str_len;
    int i;

    char *str_start; //Pointers that point at the beginning and the end of the string
    char *str_end;

    char temp; //Holder variable

    str_start = str; //Sets the pointer to point at the start of the input string



    for (str_len = 0; *str != '\0'; str++) //Loops through the string and increments the counter value until the null-terminating character is reached
    {
      str_len ++;
    }

    str = str - str_len; //This resets the original pointer to point to the first character in the character array (string)


    for (i=0; i < (str_len / 2); i++)  //This loops iterates through the characters in the string up to the mid-way point
                                        //The loop stores the value of *str_start in a holder variable (temp) and then replaces the value of of *str_start with *str_end (the last character of the string)

    {
      str_end = (str + str_len - 1 - i); //This sets str_end to point at the last character in the string and then moves it backward as the iterator increases
                                        //The -1 accomodates for the null termination at the end of the address space
      temp = *str_start;
      *str_start = *str_end;
      *str_end = temp;

      str_start++;
    }
}


int main ()
{
    char test_string[] = "Hello World";
    reverso(test_string);
    printf(test_string);


}
