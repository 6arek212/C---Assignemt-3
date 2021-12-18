#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_mainpulation.h"

int isLetter(char ch)
{
    if (ch <= 'z' && ch >= 'a')
        return 1;

    if (ch <= 'Z' && ch >= 'A')
        return 1;
    return 0;
}

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
    char *newStr = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    return strcpy(newStr, str);
}

void gematriaSequences(char *str, int len, char *word)
{
    int flag = 1;
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

                    if (flag && gimetriaSum(s) == sum)
                    {
                        printf("%s", s);
                        flag = 0;
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

void strToAtbash(char *str)
{
    while (*str)
    {
        *str = chToItbash(*str);
        str++;
    }
}

void atbashSequences(char *str, int len, char *word)
{
    char *copiedWord = strCopy(word);
    char *copiedreverse = strCopy(word);

    strToAtbash(copiedWord);
    strToAtbash(copiedreverse);
    reverseWord(copiedreverse, strlen(copiedreverse));

    int flag = 1;

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

                    if ((areEquals(s, copiedWord) || areEquals(s, copiedreverse)) && flag)
                    {
                        printf("%s", s);
                        flag = 0;
                    }
                    else if (areEquals(s, copiedWord) || areEquals(s, copiedreverse))
                    {
                        printf("~%s", s);
                    }

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
        if (!isLetter(*str) && *str != ' ')
        {
            return 0;
        }
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
    int flag = 1;

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
                    if (flag && hasAllCharsInWord(s, word))
                    {
                        printf("%s", s);
                        flag = 0;
                    }
                    else if (hasAllCharsInWord(s, word))
                        printf("~%s", s);

                    free(p);
                }
            }
    }
}
