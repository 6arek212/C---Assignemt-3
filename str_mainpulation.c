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

    while (str)
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

int printAll(char *str, int sum, int wordSum)
{
    if (sum > wordSum || str == NULL)
    {
        return -1;
    }

    int x = printAll(str + 1, sum + charToNum(*str), wordSum);

    if (x == wordSum && charToNum(*str) != 0)
    {
        printf("%d", *str);
        return x;
    }
    return printAll(str + 1, sum, wordSum);
}

int main()
{
    char *word = "bee";
    char *text = "I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee– OUCH !!It stung me !!~";

    printAll(text, 0, gimetriaSum(word));
    

    return 0;
}