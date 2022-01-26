#include <stdio.h>
#include <cs50.h>

int checker(long credit);
int type(long credit);
int main(void)
{
  long credit;

  do
  {
    credit = get_long("Number: ");
  }
  while (credit <= 0);

  int c = checker(credit);
  int t = type(credit);

  if(!c || !t)
  {
    printf("INVALID\n");
  } 
  else 
  {
    if (t == 1) 
    {
      printf("AMEX\n");
    } 
    else if (t == 2) 
    {
      printf("MASTERCARD\n");
    } 
    else 
    {
      printf("VISA\n");
    }
  }
}

int type(long credit)
{
  int counter = 0;
  while(credit >= 100)
  {
    credit /= 10;
    counter++;
  }
  counter += 2; 
  if(counter == 15 && (credit == 34 || credit == 37))
    return 1;
  else if (counter == 16 && (credit >= 50 && credit <= 55))
    return 2;
  else if ((counter == 13 || counter == 16) && credit/10 == 4)
    return 3;
  else
    return 0;
}

int checker(long credit)
{
  long aux = credit;
  int sum = 0, temp;

  credit /= 10;
  while(credit)
  {
    temp = (credit % 10) * 2;
    if (temp >= 10)
    {
      sum += (temp % 10) + (temp / 10);
    }
    else
    {
      sum += temp;
    }
    credit = credit / 100;
  }

  credit = aux;
  while(credit)
  {
    sum += credit % 10;
    credit /= 100;
  }
  if(sum % 10 == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}