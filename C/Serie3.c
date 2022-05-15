# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define foreach(type, i, x) for(type* i = &x; i < &x + (sizeof(x) / sizeof(*x)); i++)
# define forstr(i, x) for(char* i = x; *i != '\0' ; i++)


void copyStrDyn(char* strIn, char* strOut)
{
    int len = strlen(strIn);
    strOut = (char*)calloc(len, sizeof(char));
    char *c, *c2;
    for (c = strIn, c2 = strOut; *c != '\0' ; c++, c2++)
        *c2 = *c;
}
void ex1()
{
    char str1[256] = "";
    char* str2 = "";
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str1);
    copyStrDyn(str1, str2);
    str1[2] = 'p';
    printf("The result is: ");
    forstr(c, str2)
        printf("%c", *c);
}

void concatStrDyn(char* strIn, char* strOut)
{
    int len = strlen(strIn);
    strOut = (char*)calloc(len, sizeof(char));
    int i = 0;
    forstr (c, strIn)
        strOut[i++] = *c;
}
void ex2()
{
    char str1[256] = "";
    char str2[0];
    printf("Enter a string: ");
    scanf("\n%[^\n]s", str1);
    concatStrDyn(str1, str2);
    printf("The result is: %s", str2);
}

void ex3()
{

}

void ex4()
{

}

void ex5()
{

}

void ex6()
{

}

int main()
{
    void (*p[6]) (void) = {ex1, ex2, ex3, ex4, ex5, ex6};
    int a;
    printf("Enter the desired exercise number: ");
    scanf("%d", &a);
    (*p[a-1])();
    return 0;
}