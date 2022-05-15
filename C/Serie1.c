# include <stdio.h>
# include <math.h>
# include <string.h>

# define foreach(type, i, x) for(type* i = &(x)[0]; i < &(x)[0] + (sizeof(x) / sizeof((x)[0])); i++)

void ex1()
{
    float r, h;
    printf("Enter radius and height: ");
    scanf("%f%f", &r, &h);
    printf("\nThe area is %f", M_PI * r * r * h);
}

void ex2()
{
    float t;
    char msg[9];
    printf("Enter the temperature: ");
    scanf("%f", &t);
    if (t < 0 || t > 100)
        return;
    else if (t <= 20)
        strcpy(msg, "cold");
    else if (t <= 50)
        strcpy(msg, "hot");
    else
        strcpy(msg, "very hot");

    printf("\nThe temperature is %s.", msg);
}

void ex3()
{
    float a, b, c, d;
    printf("Consider f(x) = ax^2 + bx + c. Enter a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);
    d = b * b - 4 * a * c;
    if (d < 0)
        printf("No real solutions exists.");
    else if (d == 0)
        printf("The root is: %f", b/(2 * a));
    else
        printf("The roots are: %f, %f", (b - sqrt(d))/(2 * a), (b + sqrt(d))/(2 * a));
}

void ex4()
{
    float a, b; char c;
    printf("Enter the operation: ");
    scanf("%f %c %f", &a, &c, &b);
    switch (c)
    {
        case '+':
        {
            printf("The result is: %.2f", a+b);
            break;
        }
        case '-':
        {
            printf("The result is: %.2f", a-b);
            break;
        }
        case '*':
        {
            printf("The result is: %.2f", a*b);
            break;
        }
        case '/':
        {
            printf("The result is: %.2f", a/b);
            break;
        }
    }
}

void ex5()
{
    int a;
    printf("Enter n: ");
    scanf("%d", &a);
    printf("The sum of integers from 1 to n is: %d", (a*(a+1))/2);
}

void ex6()
{
    float sum, in; int n = 0;
    printf("Please enter a grade: ");
    scanf("%f", &in);
    while (in >= 0 && in <= 20)
    {
        sum += in;
        ++n;
        printf("Please enter a grade: ");
        scanf("%f", &in);
    }
    printf("Your average grade is: %.2f", sum / n);
}

void ex7()
{
    double base, intRate; int year;
    printf("Please enter the base amount, the interest rate, and the number of years: ");
    scanf("%lf %lf %d", &base, &intRate, &year);
    printf("The account now holds %.2lf", base * pow(1+intRate, year));
}

void ex8()
{
    int a;
    printf("Enter the maximum n: ");
    scanf("%d", &a);

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a; j++)
            printf("%4d ", i * j);
        printf("\n");
    }
}

long long int fact(int n)
{
    long long int out = 1;
    for (int i = n; i > 1; i--)
        out *= i;
    return out;
}
double powI(double x, int y)
{
    int out = 1;
    for (int i = y; i > 0; i--)
        out *= x;
    return out;
}
int composition(int n, int p)
{
    return fact(n)/(fact(n-p) * fact(p));
}
void ex9()
{
    int a, b, c, d, e;
    printf("Enter n: ");
    scanf("%d", &a);
    printf("%d! = %d", a, fact(a));
    printf("\nEnter a and b: ");
    scanf("%d %d", &b, &c);
    printf("%d^%d = %d", b, c, powI(b, c));
    printf("\nEnter n and p: ");
    scanf("%d %d", &d, &e);
    printf("%d C %d = %d", d, e, composition(d, e));
}

double eulerPi(int n)
{
    double out = 0.l;
    for (int i = n; i > 0; i--)
        out += 1.l/pow(i, 4.l);
    return pow(out * 90.l, 1.l/4.l);
}
void ex10()
{
    int a;
    printf("Enter the level of precision: ");
    scanf("%d", &a);
    printf("The approximate value of pi is %.16lf", eulerPi(a));
}


double func(double x)
{
    return (pow(x, 2) + x)/2;
}
double dichotomie(double (*f)(double), double a, double b, int e)
{
    double n = (a+b)/2.;
    double fn = f(n);
    if ((-pow(10, -e)) < fn && fn < pow(10, -e))
        return n;
    if (fn * f(a) > 0)
        return dichotomie(f, n, a, e);
    return dichotomie(f, n, b, e);
}
void ex11()
{
    double a, b;
    int e;
    printf("Enter the lower bound, the upper bound, and the precision level: ");
    scanf("%lf %lf %d", &a, &b, &e);
    printf("The root found is in x = %lf", dichotomie(func, a, b, e));
}

double rootN(double a, double n, int k)
{
    if (k == 0)
        return a/n;
    double lastA = rootN(a, n, k-1);
    return (pow(lastA, n) * (n-1) + a)/(n * pow(lastA, n-1));
}
void ex12()
{
    double a, b;
    int c;
    printf("Consider root(x, n). Enter x, n and the precision: ");
    scanf("%lf %lf %d", &a, &b, &c);
    printf("The approximate result is: %.16lf", rootN(a, b, c));
}

int main ()
{
    void (*p[12]) (void) = {ex1, ex2, ex3, ex4, ex5, ex6, ex7, ex8, ex9, ex10, ex11, ex12};
    int a;
    printf("Enter the desired exercise number: ");
    scanf("%d", &a);
    (*p[a-1])();
    return 0;
}
