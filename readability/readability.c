#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_grade(int letters, int words, int sentences);

int main(void)
{
    // Get the input from user
    string text = get_string("Text: ");

    // Get the letter count
    int letters = count_letters(text);
    
    // Get the word count
    int words = count_words(text);

    // Get the sentence count
    int sentences = count_sentences(text);

    // Get the grade
    int grade = calculate_grade(letters, words, sentences);

    // Run grade checks
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else 
    {
        printf("Grade %i\n", grade);
    }
}


// Implement the count letter function
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char current = toupper(text[i]);

        if (current >= 'A' && current <='Z')
        {
            letters += 1;
        }
    }

    return letters;
}


// Implement the count word function
int count_words(string text)
{
    int words = 0;

    if (text)
    {
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            if (text[i] == ' ' && text[i - 1] != ' ' && text[i + 1] != ' ')
            {
                words += 1;
            }
        }

        return words + 1;
    }

    return 0;
    
}


// Implement the count sentence function
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char current = text[i];
        if (current == '.' || current == '?' || current == '!'){
            sentences += 1;
        }
    }

    return sentences;
}

// Implement the grade count function
int calculate_grade(int letters, int words, int sentences)
{
    int index;

    int L = (letters * 100) / words;

    int S = (sentences * 100) / words;

    index = 0.0588 * L - 0.296 * S - 15.8;

    return index;
}