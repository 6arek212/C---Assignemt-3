#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_mainpulation.h"

int charToNum(char ch)
{
    if (ch <= 'z' && ch >= 'a')
        return ch - 'a' + 1;

    if (ch <= 'Z' && ch >= 'A')
        return ch - 'A' + 1;
    return 0;
}

int gimetriaSum(char *str)
{
    int sum = 0;

    while (*str)
    {
        sum += charToNum(*str);
        str++;
    }

    return sum;
}

char *strCopy(char *str)
{
    char *newStr = (char *)malloc(sizeof(char) * strlen(str));
    return strcpy(newStr, str);
}

void gematriaSequences(char *str, int len, char *word)
{
    int flag = 0;
    int sum = gimetriaSum(word);

    for (int i = 0; i < len; i++)
    {
        if (charToNum(*(str + i)) > 0)

            for (int j = i; j < len; j++)
            {
                if (charToNum(*(str + j)) > 0)
                {

                    char *s = strCopy(str);
                    char *p = s;

                    s[j + 1] = '\0';
                    s += i;

                    if (flag == 0 && gimetriaSum(s) == sum)
                    {
                        printf("%s", s);
                        flag = 1;
                    }
                    else if (gimetriaSum(s) == sum)
                        printf("~%s", s);

                    free(p);
                }
            }
    }
}

void reverseWord(char *str, int len)
{

    int i = 0;
    int k = len - 1;
    while (i < len / 2)
    {
        int temp = *(str + i);
        *(str + i) = *(str + k);
        *(str + k) = temp;
        k--;
        i++;
    }
}

char chToItbash(char ch)
{
    if (ch <= 'z' && ch >= 'a')
        return 'z' - (ch - 'a');

    if (ch <= 'Z' && ch >= 'A')
        return 'Z' - (ch - 'A');

    return ch;
}

void removeSpace(char *str)
{
    char *p = str;

    while (*p)
    {
        if (*p == ' ')
        {
            *p = '\0';
            strcpy(str, p + 1);
        }
        else
            p++;
    }
}

int areEquals(char *str1, char *str2)
{

    while (*str1 && *str2)
    {
        if (*str1 == ' ')
            str1++;
        else if (*str2 == ' ')
            str2++;
        else if (*str2 != *str1)
            return 0;
        else
        {
            str1++;
            str2++;
        }
    }

    if (!*str1 && *str2)
        return 0;

    if (*str1 && !*str2)
        return 0;

    return 1;
}

void strToItbash(char *str)
{
    while (*str)
    {
        *str = chToItbash(*str);
        str++;
    }
}

void itbashSequences(char *str, int len, char *word)
{
    char *copiedWord = strCopy(word);
    char *copiedreverse = strCopy(word);

    strToItbash(copiedWord);
    strToItbash(copiedreverse);
    reverseWord(copiedreverse, strlen(copiedreverse));


    for (int i = 0; i < len; i++)
    {
        if (charToNum(*(str + i)) > 0)

            for (int j = i; j < len; j++)
            {
                if (charToNum(*(str + j)) > 0)
                {

                    char *s = strCopy(str);
                    char *p = s;
                    s[j + 1] = '\0';
                    s += i;

                    strToItbash(s);
                    if (areEquals(s, copiedWord) || areEquals(s, copiedreverse))
                        printf("%s~", s);

                    free(p);
                }
            }
    }

    free(copiedWord);
    free(copiedreverse);
}

int hasAllCharsInWord(char *str, char *word)
{
    int arr1[27] = {0};

    while (*str)
    {
        arr1[charToNum(*str)]++;
        str++;
    }

    int arr2[27] = {0};

    while (*word)
    {
        arr2[charToNum(*word)]++;
        word++;
    }

    for (int i = 1; i < 27; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0;
        }
    }

    return 1;
}

void anagramSequences(char *str, int len, char *word)
{
    int flag = 0;

    for (int i = 0; i < len; i++)
    {
        if (charToNum(*(str + i)) > 0)

            for (int j = i; j < len; j++)
            {
                if (charToNum(*(str + j)) > 0)
                {

                    char *s = strCopy(str);
                    char *p = s;
                    s[j + 1] = '\0';
                    s += i;
                    if (flag == 0 && hasAllCharsInWord(s, word))
                    {
                        printf("%s", s);
                        flag = 1;
                    }
                    else if (hasAllCharsInWord(s, word))
                        printf("~%s", s);

                    free(p);
                }
            }
    }
}

// int main()
// {
//     char word[WORD] = "bee";
//     char text[TXT] = "I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee– OUCH !!It stung me !!~";

//     // print_substrings(text, strlen(text), gimetriaSum(word));
//     // printItbash(text, strlen(text), word);

//     anagramSequences(text, strlen(text), word);
//     return 0;
// }