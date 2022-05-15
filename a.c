# include "Lib/Time/time.h"

int main()
{
	Ttime a;
	Ttime b = newtime(10, 10);

	while (scanf("%d:%2d", &a.hrs, &a.min) != 2);

	printtime(addtime(a, b));
}