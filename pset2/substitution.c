#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    } else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    char test[25];
    for (int i = 0; i < 26; i++) 
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Be sure that you typed valid letters!");
            return 1;
        }
        for (int j = 0; j < 26; j++)
        {
            if(argv[1][i] == test[j]) 
            {
                printf("There is duplicated letters!\n");
                return 1;
            }
        }
        test[i] = argv[1][i];
    }

    string text = get_string("plaintext: ");
    string stdl = "abcdefghijklmnopqrstuvwxyz", stdu = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string c = argv[1], final = calloc(strlen(text)+1, sizeof(char));

    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] >= 'a' && text[i] <= 'z') {
                if (text[i] == stdl[j]) 
                {
                    final[i] = tolower(argv[1][j]);
                }
            } 
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                if (text[i] == stdu[j])
                {
                    final[i] = toupper(argv[1][j]);
                }
            }
            else
            {
                final[i] = text[i];
            }
        }
    }

    printf("ciphertext: %s\n", final);
    
}