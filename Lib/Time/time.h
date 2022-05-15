// * Includes
# include <stdio.h>

# ifndef TIME_H
# define TIME_H
typedef struct Ttime { int hrs; int min; } Ttime;
# endif

// * Functions
Ttime newtime(int, int);
Ttime addtime(Ttime, Ttime);
void printtime(Ttime);