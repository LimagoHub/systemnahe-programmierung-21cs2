
#include "einundausgabe.h"


static int mswstsatz=19; // static ist das private von Java

void set_mswstsatz(int value)
{
	if( value == 19 || value == 7)
		mswstsatz = value;
}

int get_mswstsatz()
{
	return mswstsatz;
}

void ausgabe()
{
	printf("Hallo\n");
}

