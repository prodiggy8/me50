#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

/*Who ever is reading this code, hello!
 *Since now, I apologize for my english, I'm not that good on writing so as I'm on listening...
 */

int main(void)
{
    int size, i, j, k, l; //=====Var declaration

    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);
    //=====Input: here we verify if the input is between 1 and 8. The function get_int() already verifies if the number is an integer


    for (i = 0; i < size; i++) //For each i value, a new line
    {
        //Subtracting the line from the total size, we'll get the spaces (The +1 is because of lines starting on 0)
        for (j = 0; j < (size - (i + 1)); j++)
        {
            printf(" "); //Fill with blank spaces
        }

        for (k = 0; k <= i; k++) //The number of the current line = the number of hashes
        {
            printf("#"); //Fill with hashes
        }

        printf("  "); //Space between

        for (l = 0; l <= i; l++) //Second part of pyramid, line = hashes
        {
            printf("#"); //Fill with hashes
        }
        printf("\n");
    }
}