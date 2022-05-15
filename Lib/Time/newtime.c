# include "time.h"

Ttime newtime(int hrs, int min)
{
	Ttime out;
	out.hrs = hrs;
	out.min = min;
	return out;
}