#include <stdio.h>
#include <cs50.h>
#include <math.h>

int cash(int value); //Prototype
int main(void)
{
    float value; //=====Var declaration

    do
    {
        value = get_float("Change owed: ");
    }
    while (value < 0); //=====Input, just positive and float values

    int coins = cash(round(value * 100)); //Value in cents, rounded for the nearest integer as argument

    printf("%i\n", coins);
    return 0;
}

int cash(int value)
{
    int coins = 0; //=====Var declaration

    while (1) //Loop until next conditional becomes true
    {
        if (!value)
        {
            return coins; //If value == 0, no more coins to pick!
        }
        else //Else, if the rest for each coin available is null, subtracts its value of the total and pick the coin
        {
            if (value >= 25)
            {
                coins++;
                value = value - 25;
            }
            else if (value >= 10)
            {
                coins++;
                value = value - 10;
            }
            else if (value >= 5)
            {
                coins++;
                value = value - 5;
            }
            else
            {
                coins++;
                value = value - 1;
            }
        }
    }
}