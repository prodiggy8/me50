#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int cripto(char letter, int key, int c);
int main(int argc, string argv[])
{
    if (argc != 2 || argv[1] < 0)
    {
        printf("this should be used with a positive integer as argument. did you forget something?\n");
        return 1;
    }


    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string text = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
          printf("%c", (char)cripto(text[i], key, 1));
        }
        else if  (text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", (char)cripto(text[i], key, 0));
        }
        else
        {
          printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}

int cripto(char letter, int key, int c)
{
    if (c)
    {
        return ((int)letter-97+key) % 26 + 97;
    }
    else
    {
        return ((int)letter-65+key) % 26 + 65;
    }
}