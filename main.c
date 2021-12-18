#include "str_mainpulation.h"
#include <stdio.h>
#include <string.h>


int main()
{
    // +1 for '\0'
    char word[WORD + 1];
    char text[TXT + 1];

    char choice;

    int i = 0;

    scanf("%c", &choice);
    while (choice != ' ' && choice != '\t' && choice != '\n' && i < WORD + 1)
    {
        word[i++] = choice;
        scanf("%c", &choice);
    }
    word[i] = '\0';

    i = 0;
    scanf("%c", &choice);
    while (choice != '~' && i < TXT + 1)
    {
        text[i++] = choice;
        scanf("%c", &choice);
    }
    text[i] = '\0';


    printf("Gematria Sequences: ");
    gematriaSequences(text, strlen(text), word);

    printf("\n");
    printf("Atbash Sequences: ");
    atbashSequences(text, strlen(text), word);

    printf("\n");
    printf("Anagram Sequences: ");
    anagramSequences(text, strlen(text), word);

    return 0;
}
