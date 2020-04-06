// Implement your program in a file called readability.c in a directory called readability.
// Your program must prompt the user for a string of text (using get_string).
// Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
// Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
// If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".

// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

// letters - words
// L - 100

// L * words = letters * 100

// L = letters * 100 / words

// S = sentences * 100 / words


#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float letters = 0;
    float words = 1;
    float sentences = 0;

    // pega o texto
    string text = get_string("What is your text?\n");
    // printf("just print: %s\n", text);


    // itera pelo texto
    for (int i = 0; text[i] != '\0'; i++)
    {
        // caractere a ser analisado no momento
        char c = text[i];

        // conta as letras
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            letters++;
        }

        // conta as palavras
        if (c == ' ')
        {
            words++;
        }

        // conta sentenças
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // printf("letters: %.1f\n", letters);
    // printf("words: %.1f\n", words);
    // printf("sentences: %.1f\n", sentences);

    float L = letters * 100 / words;
    float S = sentences * 100 / words;

    // printf("L: %f\n", L);
    // printf("S: %f\n", S);

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // printf("index: %f\n", index);

    int grade = round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }


}