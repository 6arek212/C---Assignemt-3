#include "str_mainpulation.h"
#include <stdio.h>
#include <string.h>

#define EOT '~' // end of text
#define LINE 256

char readLine(char Line[])
{
    int i = 1;
    char c = getc(stdin);

    while (c != '\n')
    {

        Line[i] = c;
        i++;
        c = getc(stdin);

        if (c == EOT)
        {
            break;
        }
    }

    if (c == EOT)
    {
        Line[i] = '~';
        Line[i + 1] = '\n';
        Line[i + 2] = '\0';
    }
    else
    {
        Line[i] = '\n';
        Line[i + 1] = '\0';
    }
    return c;
}

void readTxT(char *txt)
{

    char line[TXT] = "";
    char c;
    while ((c = getc(stdin)) != EOT)
    {
        if (c != '\n')
        {
            line[0] = c;
            char t = readLine(line);
            strcat(txt, line);
            if (t == EOT)
            {
                break;
            }
        }
    }

    printf("txt --> :\n %s", txt);
}

void readWord(char word[])
{
    int i = 0;
    char c = getc(stdin);

    if (c == EOT)
    {
        return;
    }

    while (c != ' ' && c != 't' && c != '\n' && c != EOT)
    {
        word[i] = c;
        i++;
        c = getc(stdin);
    }

    word[i] = '\0';
}

int main(int argc, char const *argv[])
{
    // +1 for '\0'
    char word[WORD + 1];
    char text[TXT + 1];

    char choice;

    int i = 0;

    // printf("enter word %d :", i);
    // scanf("%c", &choice);
    // while (choice != ' ' && choice != '\t' && choice != '\n' && i < WORD)
    // {
    //     word[i++] = choice;
    //     // printf("enter word %d :", i);
    //     scanf("%c%c", &choice, &choice);
    // }
    // word[i] = '\0';
    readWord(word);
    // printf("\n");

    i = 0;
    printf("enter txt %d :", i);
    scanf(" %c", &choice);
    while (choice != '`' && i < TXT)
    {
        text[i++] = choice;
        // printf("enter txt %d :", i);
        scanf("%c%c", &choice, &choice);
    }
    text[i] = '\0';

    //readTxT(text);

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
