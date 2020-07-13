#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int getLetters(string text);
int getWords(string text);
int getSentences(string text);

int main(void)
{
    // Get the text
    string text = get_string("Text: ");

    // Calculate the number of letters in the text
    int letters = getLetters(text);

    // Calculate the number of words in the text
    int words = getWords(text);

    // Calculate the number of sentences in the text
    int sentences = getSentences(text);

    // Calculate the L  and S
    float L = letters * 100 / (float) words;
    float S = sentences * 100 / (float) words;

    // Applying the Coleman-Liau index
    float grade = 0.0588 * L - 0.296 * S - 15.8;

    // Printing the grade of the text
    if (grade > 1 && grade < 17)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int getLetters(string text)
{
    int letters = 0;

    // For each char of the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if is a uppercap char
        if (text[i] > 64 && text[i] < 91)
        {
            letters += 1;
        }
        // Or a lowercap char
        else if (text[i] > 96 && text[i] < 123)
        {
            letters += 1;
        }
    }

    return letters;
}

int getWords(string text)
{
    int words = 0;

    // For each char of the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if is a space
        if (text[i] == 32)
        {
            words += 1;
        }
    }

    // Adding the last word (that not have a space after)
    words += 1;

    return words;
}

int getSentences(string text)
{
    int sentences = 0;

    // For each char of the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if is a point
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences += 1;
        }
    }

    return sentences;
}