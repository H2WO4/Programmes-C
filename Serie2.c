# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

# define foreach(type, i, x) for(type* i = &(x)[0]; i < &(x)[0] + (sizeof(x) / sizeof(*x)); i++)
# define forstr(i, x) for(char* i = &(x)[0]; i < &(x)[0] + strlen(x); i++)

void upperStr(char* str)
{
    forstr (c, str)
        *c = toupper(*c);
}
void ex1 ()
{
    char str[256] = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str);
    upperStr(str);
    printf("The output is: %s", str);
}

int countStr(char* str)
{
    int i = 0;
    while (str[i++]) {}
    return --i;
}
void ex2 ()
{
    char str[256] = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str);
    printf("The size of the string is: %d", countStr(str));
}

void inStrFull(char* str)
{
    scanf("\n%[^\n]s", str);
}
void inStrOne(char* str)
{
    char c; int i = 0;
    getchar();
    while ((c = getchar()) != '\n')
        str[i++] = c;
}
void ex3 ()
{
    char str1[256] = "";
    char str2[256] = "";
    inStrFull(str1);
    inStrOne(str2);
    printf("The output is: %s, %s", str1, str2);
}

void copyStr(char* str1, char* str2)
{
    int i = 0;
    forstr (c, str1)
        str2[i++] = *c;
}
void ex4 ()
{
    char str1[256] = "";
    char str2[256] = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str1);
    copyStr(str1, str2);
    printf("The output is: %s", str2);
}

bool compStr(char* str1, char* str2)
{
    int i = 0;
    bool out = true;
    forstr (c, str1)
        if (str2[i++] != *c)
        {
            out = false;
            break;
        }
    return out;
}
void ex5 ()
{
    char str1[256] = "";
    char str2[256] = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str1);
    printf("Enter a second string: ");
    scanf("\n%[^\n]s", str2);
    printf("The strings%s are equal.", compStr(str1, str2) ? "" : " not");
}

void concatStr(char* str1, char* str2, char* str3)
{
    int i = 0;
    forstr (c, str1)
        str3[i++] = *c;
    forstr (c, str2)
        str3[i++] = *c;
}
void concatStrInP(char* str1, char* str2)
{
    int i = strlen(str1);
    forstr (c, str2)
        str1[i++] = *c;
}
void ex6 ()
{
    char str1[256] = "";
    char str2[256] = "";
    char str3[256] = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str1);
    printf("Enter a second string: ");
    scanf("\n%[^\n]s", str2);
    concatStr(str1, str2, str3);
    concatStrInP(str1, str2);
    printf("The output is: %s; %s", str1, str3);
}

bool palindrome(char* str)
{
    int i = 0, n = strlen(str);
    bool out = true;
    for(char* c = &str[0]; c < &str[0] + n/2; c++)
        if (str[i] != str[n-1-i++])
        {
            out = false;
            break;
        }
    return out;
}
void ex7 ()
{

    char str1[256] = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str1);
    printf("The string is%s a palindrome.", palindrome(str1) ? "" : " not");
}

void reverseStr(char* str1, char* str2)
{
    int i = 0, n = strlen(str1);
    forstr (c, str1)
        str2[n-1-i++] = *c;
}
void reverseStrInP(char* str)
{
    int i = 0, n = strlen(str);
    for(char* c = &str[0]; c < &str[0] + n/2; c++)
    {
        char tmp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i++] = tmp;
    }
}
void ex8 ()
{
    char str1[256] = "";
    char str2[256] = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str1);
    reverseStr(str1, str2);
    reverseStrInP(str1);
    printf("The output is: %s; %s", str1, str2);
}

int parseStrInt(char* str)
{
    int out, n = strlen(str) - 1;
    forstr(c, str)
        out += (*c - 48) * pow(10, n--);
    return out;
}
void ex9 ()
{
    char str1[256] = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str1);
    printf("The output is: %d", parseStrInt(str1));
}

int main()
{
    void (*p[9]) (void) = {ex1, ex2, ex3, ex4, ex5, ex6, ex7, ex8, ex9};
    int a;
    printf("Enter the desired exercise number: ");
    scanf("%d", &a);
    (*p[a-1])();
    return 0;
}
