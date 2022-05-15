# include "time.h"

Ttime addtime(Ttime t1, Ttime t2)
{
	Ttime out;
	out.hrs = t1.hrs + t2.hrs;
	out.hrs += (t1.min + t2.min) / 60;
	out.min = (t1.min + t2.min) % 60;
	return out;
}