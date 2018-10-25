/*
* sudoku.c
*
* Trame du TP de C intitulé sudoku.c
* Seule la fonction generer() du TP est véritablement codée.
* Avant de coder, il faudra choisir si les variables grille et remplissage sont locales ou globales
*
* Loic - 19/09/2016
*/

#include <stdio.h>

int initialiser()
{
	return 0;
}

void afficher()
{

}

int generer(int tab[][9]) 
{
	
	int i, j, k;

	for(j=0;j<9; ++j) 
	{
		for(i=0; i<9; ++i)
			tab[j][i] = (i + j*3 +j /3) %9 +1 ; 
	}

	for(i=0;i<9; ++i)
	{
		for(j=0; j<9; ++j)
			printf("%d ", tab[i][j]);
		printf("\n");
	}

	return 81;
}

int saisir(int i, int j) 
{
	return 0;
}

int verifierLigneColonne(int i, int sens)
{
	return 0;
}

int verifierRegion(int k, int l)
{
	return 0;
}

int verifierGrille() {
	return 0;
}

int main()
{
	return 0;
}