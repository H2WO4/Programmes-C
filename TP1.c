# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# define foruntil(type, i, x, lim) for(type* i = x; *i != lim; ++i)

bool isPrime(int n)
{
    bool out = n % 2 != 0 || n == 2;
    for (int j = 3; j < sqrt(n) + 1 && out; j += 2)
        out = n % j != 0;

    return out;
}

void ex1()
{
    int n, i = 0, *pList;
    printf("Enter the upper bound: ");
    scanf("%d", &n);

    pList = (int*) realloc(pList, (i+1) * sizeof(int));
    pList[i++] = 2;
    for (int k = 3; k < n; k += 2)
    {
        if (isPrime(k))
        {
            pList = (int*) realloc(pList, (i+1) * sizeof(int));
            pList[i++] = k;
        }
    }
    pList = (int*) realloc(pList, (i+1) * sizeof(int));
    pList[i] = -1;

    foruntil(int, e, pList, -1)
    {
        printf("%d ", *e);
    }
}

int main()
{
    void (*p[1]) (void) = {ex1};
    int a;
    printf("Enter the desired exercise number: ");
    scanf("%d", &a);
    if (a > 0 && a <= 1)
        (*p+a-1)();

    return 0;
}