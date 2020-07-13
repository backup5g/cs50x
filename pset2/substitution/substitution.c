#include <stdio.h>
#include <cs50.h>
#include <string.h>

int checkKey(string key);
string toUppercase(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You need to pass a key\n");
        return 1;
    }

    // Get the key to encrypt
    if (checkKey(argv[1]) == 1)
    {
        return 1;
    }

    string key = toUppercase(argv[1]);

    // Put the normal alphabet in a array
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Get the diference between the letters of the key and the alphabet
    int diference[26];

    for (int j = 0; j < 27; j++)
    {
        diference[j] = alphabet[j] - key[j];
    }

    // Get the plain text
    string text = get_string("plaintext:  ");

    // Encrypt
    for (int l = 0; l < strlen(text); l++)
    {
        if (text[l] > 64 && text[l] < 91)
        {
            text[l] -= diference[text[l] - 65];
        }
        else if (text[l] > 96 && text[l] < 123)
        {
            text[l] -= diference[text[l] - 97];
        }
    }

    // Print the result
    printf("ciphertext: %s\n", text);
}

// Check if the key is valid
int checkKey(string key)
{
    int clone[26];

    if (strlen(key) != 26)
    {
        printf("The key must contain 26 characters\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (key[i] < 65 || key[i] > 90)
            {
                if (key[i] < 97 || key[i] > 122)
                {
                    printf("The key must only have letters\n");
                    return 1;
                }
            }

            for (int j = 0; j <= i; j++)
            {
                if (clone[j] == key[i])
                {
                    printf("Your key cannot have repeated characters\n");
                    return 1;
                }
            }

            clone[i] = key[i];
        }
    }

    return 0;
}

// Transform lowercase letters in the key to uppercase
string toUppercase(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (key[i] > 96 && key[i] < 123)
        {
            key[i] -= 32;
        }
    }
    return key;
}

