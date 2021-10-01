#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Check key
    // Not enough argument
    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }
    // Argument is invalide
    else if (strlen(argv[1]) != 26)
    {
        printf("Key most contain 26 characters\n");
        return 1;
    }
    else
    {
        for (int i = 0 ; i < strlen(argv[1]) ; i++)
        {
            if (argv[1][i] < 'A' || argv[1][i] > 'z')
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            for (int j = i + 1; j < strlen(argv[1]); j++)
            {
                if (argv[1][j] == argv[1][i] || argv[1][j] == (argv[1][i] - 32))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }

        }
    }


    string s = get_string("plaintext: ");

    //Create output variable have length which similar to input
    string encode = s;
    //Ajusting a key to an upper string
    //Create new variable for key
    string up = argv[1] ;

    // Convert the key to upper
    for (int i = 0, n = strlen(up); i < n; i++)
    {
        if (islower(up[i]))
        {
            up[i] = toupper(up[i]);
        }

    }
    // Encode

    int index = 0;
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        // Encode upper character
        if (isupper(s[i]))
        {
            index = (int)(s[i]) - 65;
            encode[i] = up[index];
        }
        // Encode lower character
        else if (islower(s[i]))
        {
            index = (int)(s[i]) - 97;
            encode[i] = up[index];
            encode[i] = tolower(encode[i]);
        }
        else
        {
            encode[i] = s[i];
        }
    }

    printf("ciphertext: %s\n", encode);
    return 0;


}
