# include <stdio.h>

int isPrime(int n)
{
    // Si n est pair, on prend false; sauf si n = 2
    int out = n % 2 != 0 || n == 2;
    // Ensuite, on teste tous les nombres impairs entre 3 et sqrt(n) + 1; si un diviseur est trouvé, on s'arrête
    for (int j = 3; j <= sqrt(n) && out; j += 2)
        out = n % j != 0;

    // On retourne le résultat
    return out;
}

void primesUntilN(int n)
{
    // Pour chaque nombre entre 2 et n, on teste si il est premier
    for (int i = 2; i <= n; i++)
        if (isPrime(i))
            // On affiche le nombre premier
            printf("%d ", i);
}

void firstNPrimes(int n) {
    // On gère le cas de 2
    if (n > 0)
        printf("2 ");
    // On initialise un compteur à 1, car 2 est déjà prit en compte
    int i = 1;
    // Pour chaque nombre impaire entre 3 et n, on teste si il est premier, tant que le nombre de nombres premiers trouvés est inférieur à n
    for (int j = 3; i < n; j += 2)
        if (isPrime(j)) {
            // On affiche le nombre premier
            printf("%d ", j);
            // On incrémente le compteur
            i++;
        }
}

int isPerfect (int n)
{
    // On initialise la somme à 1, car 1 divise tout nombre
    int sum = 1;
    // Pour chaque nombre entre 2 et n, on teste si il est divisible par n
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            // Si c'est le cas, on ajoute i à la somme
            sum += i;

    // On retourne si la somme est égale à n
    return sum == n;
}

void perfectUntilN(int n)
{
    // Pour chaque nombre entre 6 et n, on teste si il est parfait
    for (int i = 6; i <= n; i++)
        if (isPerfect(i))
            // On affiche le nombre parfait
            printf("%d ", i);
}

void firstNPerfect(int n)
{
    // On initialise un compteur à 0
    int i = 0;
    // Pour chaque nombre entre 6 et n, on teste si il est parfait, tant que le nombre de nombres parfaits trouvés est inférieur à n
    for (int j = 6; i < n; j++)
        if (isPerfect(j)) {
            // On affiche le nombre parfait
            printf("%d ", j);
            // On incrémente le compteur
            i++;
        }
}

int main()
{
    // On demande un nombre
    printf("Entrez un nombre : ");
    int n; scanf("%d", &n);

    firstNPerfect(n);

    return 0;
}