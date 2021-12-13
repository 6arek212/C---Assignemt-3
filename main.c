#include "str_mainpulation.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char word[WORD];
    char text[TXT];

    char choice = '\\';
    char e;

    int i = 0;

    while (choice != ' ')
    {
        printf("enter word %d :", i);
        scanf("%c%c", &choice ,&e);

        if (choice != ' ')
           { word[i++] = choice;
           }
    }
    printf("\n");

    i = 0;
    while (choice != '`')
    {
        printf("enter text %d :", i);
        scanf("%c%c", &choice ,&e);

        if (choice != '`')
            text[i++] = choice;
    }
    
    
    printf("\n");
    printf("Anagram Sequences: ");
    anagramSequences(text, strlen(text), word);

    printf("\n");
    printf("Atbash Sequences : ");

    printf("\n");
    printf("Gematria Sequences: ");
    printf("\n");

    return 0;
}
