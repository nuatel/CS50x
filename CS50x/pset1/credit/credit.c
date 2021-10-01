#include <cs50.h>
#include <stdio.h>


int main(void)
{
    //This program checks the validation of credit card
    //This get input number through get_long function, because int is not enough
    //space for stored number with more than 10 digit
    //After that in while loop, this reduce the number by 10 times and count number of digit into i
    //Simulatiously, this will calculate the sum of odd and even digit index of ID number

    long n;
    int sum1 = 0;
    int sum2 = 0;
    int i = 0;

    // Get input number as Long type
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);




    long number = n;
    // Caculate by Luhn's Algorithm
    while (n > 0)
    {
        //Number digit of ID number: i
        i++;
        //Take care even index
        if (i % 2 == 0)
        {
            //even index is extract by div, and multiply by 2
            int d = (n % 10) * 2;
            // sum number has even index
            sum1 = sum1 + d / 10 + d % 10;
            // remove number after processing
            n = n / 10;
        }
        //Take care odd index
        else
        {
            sum2 = sum2 + n % 10;
            n = n / 10;
        }

    }

    int sum = sum1 + sum2;

    int x = i - 2;

    for (int j = 0; j < x; j++)
    {
        number = number / 10;
    }
    int id_number = number;


    if (sum % 10 == 0)
    {
        if (id_number >= 51 && id_number <= 55 && i == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (((id_number == 34) || (id_number == 37)) && (i == 15))
        {
            printf("AMEX\n");

        }
        else if ((id_number >= 40) && (id_number <= 49) && (i == 13 || i == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }



}


int even_sum(long n)
{
    int sum1 = 0;
    int i = 0;
    while (n > 0)
    {
        i++;
        if (i % 2 == 0)
        {
            int d = (n % 10) * 2;
            sum1 = sum1 + d / 0 + d % 10;
        }
        n = n / 10;

    }

    return sum1;
}


int odd_sum(long n)
{
    int sum2 = 0;
    int i = 0;

    while (n > 0)
    {
        i++;
        if (i % 2 == 1)
        {
            sum2 = sum2 + n % 10;
        }
        n = n / 10;

    }

    return sum2;
}

int sum(long n)
{
    int sum1 = 0;
    int sum2 = 0;
    int i = 0;
    while (n > 0)
    {
        i++;
        if (i % 2 == 0)
        {
            int d = (n % 10) * 2;
            sum1 = sum1 + d / 10 + d % 10;
            n = n / 10;
        }
        else
        {
            sum2 = sum2 + n % 10;
            n = n / 10;
        }

    }
    int x = sum1 + sum2;
    return x;
}




