#include <stdio.h>
#include <stdlib.h>
#define s1Smaller -1  //Defined Macros for strcmp() returns
#define s2Smaller 1
#define stringEqual 0


int getLength (char *str) //Borrowed from da1_part2.c, modified to use int instead of uint32_t

{
    int strLength;

    for (strLength = 0; *str != '\0'; str ++)
        strLength++;

    return strLength;
}

//The function strcmp() will compare the two strings using the following method
// 1. Compare the two lengths of the strings
//          - Whichever is the smallest will be what the iterator counts up to
// 2. Parse through each character in the strings
//          - The first inequality between the two results in the program go into an if-else control block
//          - If the character of the first string has a greater value than that of the second string, the function will return 1, etc.
// 3. If the function has parsed through all of the characters up to the limit set by the smallest string length, the function will return 0
//          - It will only reach this limit if all the characters are equal

int strcmp (char *str1, char* str2, int length1, int length2)
{
    int compLength;
    int i;

    if (length1 > length2) //Compares the lengths of the two strings, and saves the shorter one into compLength
        compLength = length2;
    else
        compLength = length1;



    for (i = 0; i < compLength; i++)
    {
        if (*str1 != *str2)
        {
            if (*str1 > *str2)
                return s2Smaller;

            else if (*str2 > *str1)
                return s1Smaller;
        }



        if (i == (compLength - 1)) //End of the string
            return stringEqual;


        str1++;
        str2++;

    }





}

int main()
{

    int str1_length;
    int str2_length;
    int result;


    char testStr1 [] = "ABDD"; //Test Strings
    char testStr2 [] = "ABCD";

    str1_length = getLength(testStr1); //Gets the lengths of both strings
    str2_length = getLength(testStr2);


    result = strcmp(testStr1,testStr2,str1_length,str2_length); //Should return 1
    printf("%d",result);


}
