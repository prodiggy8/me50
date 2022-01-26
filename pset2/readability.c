#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    int sentences = 0, words = 1, letters = 0;
    float index;
    string text = get_string("Input some text: ");

    for (int i = 0, n = strlen(text); i < n; i++) 
    {
        if (isblank(text[i]))
            words++;
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
        else if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            letters++;
        else
            continue;
    }

    index = 0.0588 * ((letters / (float) words) * 100) - 0.296 * ((sentences / (float) words) * 100) - 15.8;
    printf("%i letter(s)\n%i word(s)\n%i sentence(s)\n\n", letters, words, sentences);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade: %i\n", (int)round(index));
    }
}