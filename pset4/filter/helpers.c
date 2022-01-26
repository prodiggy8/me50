#include <math.h>
#include "helpers.h"

int overflow(int number) //Overflow 8 bits test and fixing
{
    if (number > 255)
    {
        return 255;
    }
    return number;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float sum, average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            average = roundf(sum / 3); //Sum and average of the colors

            image[i][j].rgbtRed   = (uint8_t)average;
            image[i][j].rgbtGreen = (uint8_t)average;
            image[i][j].rgbtBlue  = (uint8_t)average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue, originalRed, originalGreen, originalBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed   = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue  = image[i][j].rgbtBlue;

            sepiaRed   = overflow((int)roundf((originalRed * .393) + (originalGreen * .769) + (originalBlue * .189)));
            sepiaGreen = overflow((int)roundf((originalRed * .349) + (originalGreen * .686) + (originalBlue * .168)));
            sepiaBlue  = overflow((int)roundf((originalRed * .272) + (originalGreen * .534) + (originalBlue * .131)));

            image[i][j].rgbtRed   = sepiaRed;
            image[i][j].rgbtGreen  = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[width];
    unsigned int len;

    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)    
        {
            buffer[j].rgbtRed   = image[i][j].rgbtRed;
            buffer[j].rgbtGreen = image[i][j].rgbtGreen;
            buffer[j].rgbtBlue  = image[i][j].rgbtBlue;
        }

        for (int j = width - 1; j >= 0; j--)
        {
            len = width - (j + 1);
            image[i][j].rgbtRed   = buffer[len].rgbtRed;
            image[i][j].rgbtGreen = buffer[len].rgbtGreen;
            image[i][j].rgbtBlue  = buffer[len].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed, sumGreen, sumBlue, counter;
    RGBTRIPLE result[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter  = 1;
            sumRed   = image[i][j].rgbtRed;
            sumGreen = image[i][j].rgbtGreen;
            sumBlue  = image[i][j].rgbtBlue;

            if (i) //Middle top pixel
            {
                sumRed   += image[i - 1][j].rgbtRed;
                sumGreen += image[i - 1][j].rgbtGreen;
                sumBlue  += image[i - 1][j].rgbtBlue;
                counter++;
            }
            if (i && j) //Left top pixel
            {
                sumRed   += image[i - 1][j - 1].rgbtRed;
                sumGreen += image[i - 1][j - 1].rgbtGreen;
                sumBlue  += image[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            if (i && (j < width - 1)) //Right top pixel
            {
                sumRed   += image[i - 1][j + 1].rgbtRed;
                sumGreen += image[i - 1][j + 1].rgbtGreen;
                sumBlue  += image[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            if (j) //Left pixel
            {
                sumRed   += image[i][j - 1].rgbtRed;
                sumGreen += image[i][j - 1].rgbtGreen;
                sumBlue  += image[i][j - 1].rgbtBlue;
                counter++;
            }
            if (j < width - 1) //Right pixel
            {
                sumRed   += image[i][j + 1].rgbtRed;
                sumGreen += image[i][j + 1].rgbtGreen;
                sumBlue  += image[i][j + 1].rgbtBlue;
                counter++;
            }
            if (i < height - 1) //Bottom pixel
            {
                sumRed   += image[i + 1][j].rgbtRed;
                sumGreen += image[i + 1][j].rgbtGreen;
                sumBlue  += image[i + 1][j].rgbtBlue;
                counter++;
            }
            if ((i < height - 1) && j) //Left bottom pixel
            {
                sumRed   += image[i + 1][j - 1].rgbtRed;
                sumGreen += image[i + 1][j - 1].rgbtGreen;
                sumBlue  += image[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            if ((i < height - 1) && (j < width - 1)) //Right bottom pixel
            {
                sumRed   += image[i + 1][j + 1].rgbtRed;
                sumGreen += image[i + 1][j + 1].rgbtGreen;
                sumBlue  += image[i + 1][j + 1].rgbtBlue;
                counter++;
            }
            result[i][j].rgbtRed   = roundf((float)sumRed   / counter);
            result[i][j].rgbtGreen = roundf((float)sumGreen / counter);
            result[i][j].rgbtBlue  = roundf((float)sumBlue  / counter); //Average and rounding to an accurate integer
        }
    }
    for (int i = 0; i < height; i++) //Writing the original array
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed   = result[i][j].rgbtRed;
            image[i][j].rgbtGreen = result[i][j].rgbtGreen;
            image[i][j].rgbtBlue  = result[i][j].rgbtBlue;
        }
    }
    return;
}
