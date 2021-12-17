#include "str_mainpulation.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // +1 for '\0'
    char word[WORD + 1];
    char text[TXT + 1];

    char choice;

    int i = 0;

    // printf("enter word %d :", i);
    scanf("%c", &choice);
    while (choice != ' ' && choice != '\t' && choice != '\n' && i < WORD)
    {
        word[i++] = choice;
        // printf("enter word %d :", i);
        scanf("%c%c", &choice, &choice);
    }
    word[i] = '\0';

    // printf("\n");

    i = 0;
    // printf("enter txt %d :", i);
    scanf(" %c", &choice);
    while (choice != '`' && i < TXT)
    {
        text[i++] = choice;
        // printf("enter txt %d :", i);
        scanf("%c%c", &choice, &choice);
    }
    text[i] = '\0';

    printf("Gematria Sequences: ");
    gematriaSequences(text, strlen(text), word);

    printf("\n");
    printf("Atbash Sequences : ");
    atbashSequences(text, strlen(text), word);

    printf("\n");
    printf("Anagram Sequences: ");
    anagramSequences(text, strlen(text), word);
    

    return 0;
}
