#include "tp2.h"

int main()
{
	int i  , *ptri  = &i;
  	char c1 = '1', *ptrc1 = &c1;
	double d, *ptrd = &d;
	char c2 = '2', *ptrc2 = &c2;
	
	double* tab = malloc(100000 * sizeof(double));

	int i_bis;

  	printf("Valeur pointe : %d\nAdresse de la variable pointe : %p\nAdresse du pointeur : %p\n", *ptri, ptri, &ptri);
	printf("Valeur pointe : %c\nAdresse de la variable pointe : %p\nAdresse du pointeur : %p\n", *ptrc1, ptrc1, &ptrc1);
	printf("Valeur pointe : %f\nAdresse de la variable pointe : %p\nAdresse du pointeur : %p\n", *ptrd, ptrd, &ptrd);

   	(*ptrd) +=2;

	printf("Valeur %f : ", *ptrd);

	printf("%p %p\n", ptrc1, ptrc2);

	swap(&ptrc1, &ptrc2);

	printf("%p %p\n", ptrc1, ptrc2);

	for(i_bis = 0; i_bis < 100000 ; i_bis++)
	{
		tab[i_bis] = i_bis*i_bis;
	}

	for(i_bis = 0; i_bis < 100000 ; i_bis++)
	{
		printf("%f\n", tab[i_bis]);
	}

	free(tab);

	return 0;
}

void echangeParValeur(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void echangeParAdresse(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(char** a, char** b)
{
	char* tmp = *a;
	*a = *b;
	*b = tmp;
}
