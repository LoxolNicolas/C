#include "mon_code.h"

int pgcd(int a, int b) 
{
	if(a%b == 0)
	{
		return b;
	}
	
	else
	{
		return pgcd(b, a%b);
	}
		
	return 0;
}
