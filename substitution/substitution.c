#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string encrypt(string plain_text, string key);

int main(int argc, string argv[])
{

    // Testing the keys
    if (argc != 2)
    {
        printf("Usage: ./subsitution 'key'\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    string key = argv[1];

    for (int i = 0,  n = strlen(key); i < n; i++)
    {
        // Convert current to uppercase
        char current = toupper(key[i]);

        // Checking if it is a alphabet
        if (current < 65 || current > 90)
        {
            printf("Key must contain only alphabets\n");
            return 1;
        }

        // Checking for duplicate letter
        for (int j = 0; j < i; j++)
        {
            if (key[j] == current)
            {
                printf("Key must only contain unique alphabets\n");
                return 1;
            }
        }
    }

    string plain_text = get_string("plain Text: ");
    string cipher_text = encrypt(plain_text, key);
    printf("ciphertext: %s\n", cipher_text);

    return 0;
}

// Implement the Cipher Text Ecryption
string encrypt(string plain_text, string key)
{
    // Declaring the cipher container
    // Using static for rigid memory allocation
    static char cipher[200];

    printf("Length: %li\n", strlen(plain_text));
    // Convert key to Uppercase
    for (int i = 0,  n = strlen(key); i < n; i++)
    {
        if islower(key[i])
        {
            key[i] = toupper(key[i]);
        }
    }

    // The ciphertext encryption
    for (int i = 0,  n = strlen(plain_text); i < n; i++)
    {
        // Initializing the string's case.
        bool string_case = false;
        char current = plain_text[i];

        // Checking if the character is an alphabet
        if (toupper(current) >= 65 && toupper(current) <= 90)
        {
            // Converting to uppercase for the encryption but also keeping track of the original
            if islower(current)
            {
                string_case = true;
                current = toupper(current);
            }

            int index = current - 65;

            if (string_case)
            {
                // Converting back to the original case
                current = tolower(key[index]);
            }

            else
            {
                current = key[index];
            }
            cipher[i] = current;

        }

        else
        {
            // Adding the non-alphabetical characters without encryption.
            cipher[i] = current;

        }
    }

    // Returning the encrypted cipher to the main function
    return cipher;
}