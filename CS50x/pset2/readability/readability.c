#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int main(void)
{
    string paragraph = get_string("Text: ");

    double letters = 0;
    // because word is counted by spaces (word = spaces + 1)
    double words = 1;
    double sentences = 0;


    for (int i = 0; i < strlen(paragraph); i++)
    {
        // paragraph[i] = (char)paragraph[i];
        if (paragraph[i] == ' ')

        {
            words++;
        }
        else if (paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!')
        {
            sentences++;
        }
        else if (paragraph[i] >= 'A' && paragraph[i] <= 'z')
        {
            letters++;
        }

    }
//    printf("strlen: %lu\n", strlen(paragraph));

//    printf("letters: %f\n", letters);

//    printf("words: %f\n", words);

//    printf("sentences: %f\n", sentences);

    double L = letters / words * 100.0;

    // printf ("L: %f\n", L);

    double S = sentences / words * 100.0;

    // printf ("S: %f\n", S);

    double index = 0.0588 * L - 0.296 * S - 15.8;

    // printf ("index: %f\n", index);

    if (index < 1.0)
    {
        printf("Before Grade 1");
    }

    else if (index < 16.0)
    {
        printf("Grade %.0f", round(index));
//      printf ("Grade %.5f", index);

    }
    else
    {
        printf("Grade 16+");
    }
    printf("\n");
}