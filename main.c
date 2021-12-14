#include "str_mainpulation.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char word[WORD];
    char text[TXT];

    char choice;

    int i = 0;

    printf("enter word %d :", i);
    scanf("%c", &choice);
    while (choice != ' ' && choice != '\t' && choice != '\n')
    {
        word[i++] = choice;
        printf("enter word %d :", i);
        scanf("%c%c", &choice, &choice);
    }
    word[i] = '\0';

    printf("\n");

    i = 0;
    printf("enter txt %d :", i);
    scanf(" %c", &choice);
    while (choice != '`')
    {
        text[i++] = choice;
        printf("enter txt %d :", i);
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
    printf("\n");

    return 0;
}
