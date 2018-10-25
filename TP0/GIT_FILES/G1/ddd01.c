/*
* Exemple d'utilisation de ddd
* Compiler le programme avec les options
*  -g -Wall -Wextra
*
* - La compilation ne dit rien
* - A l'execution, il est possible de ne rien voir suivant la configuration
* - Le comportement a probleme est signale par valgrind a l execution
*/

#include<stdio.h>

void essai(int j) 
{
	int i;
	
	while(i<10) 
	{
		printf("%d ", i+j );
		++i;
	}
}

int main() 
{
	int j;

    for(j=0; j< 10; ++j)  
    {
    	essai(j);
    	printf("\n");
    }
	
	return 0;
}
