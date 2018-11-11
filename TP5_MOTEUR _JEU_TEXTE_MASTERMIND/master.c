#include "master.h"

void initialiser_solution(int tabS[NB_COLONNES]) 
{
	int i = 0;
	
	for(i = 0; i < NB_COLONNES; i++)
	{
		tabS[i] = (rand() % 6) + 1;
	}
}


void initialiser_plateau(int plateau[NB_LIGNES][NB_COLONNES + 2])
{
	int i, j;
	
	for(i = 0; i < NB_LIGNES; i++)
	{
		for(j = 0; j < NB_COLONNES + 2; j++)
		{
			plateau[i][j] = 0;
		}
	}
}

/*
void compiler_proposition(int prop[NB_COLONNES], int sol[NB_COLONNES], int* bp, int* mp) 
{
	
}
*/

void saisie(int prop[NB_COLONNES])
{
	int i = 0;
	
	printf("Saisir un jeu de couleur comme 1 1 2 3, valider par entree\n");
	printf("Votre code : ");
	scanf("%d %d %d %d", &prop[0], &prop[1], &prop[2], &prop[3]);
	
	for(i = 0; i < NB_COLONNES; i++)
	{
		while(prop[i] < 1 || prop[i] > 6)
		{
			printf("Veuillez saisir un numero compris entre 1 et 6 par la case %d : ", (i+1));
			scanf("%d", &prop[i]);		
		}
	}
}

void MajPlateau(int plateau[NB_LIGNES][NB_COLONNES + 2], int prop[NB_COLONNES], int bp, int mp, int nbcoup)
{
	int i, j;
	
	for(i = nbcoup; i < (nbcoup + 1) ; i++)
	{
		for(j = 0; j < (NB_COLONNES + 2); j++)
		{
			switch(j)
			{
				case 4:
					plateau[i][j] = bp;
					break;
					
				case 5:
					plateau[i][j] = mp;
					break;
					
				default:
					plateau[i][j] = prop[j];
					break;
			}
		}
	}
}

void affichagePlateau(int plateau[NB_LIGNES][NB_COLONNES +2])
{
	int i, j;
	
	printf("================b==m==\n");
	for(i = 0; i < NB_LIGNES ; i++)
	{
		printf("|");
		for(j = 0; j < (NB_COLONNES + 2); j++)
		{
			if(j == 4)
			{
				couleur("32");
				printf(" %d ", plateau[i][j]);
				couleur("0");
			}
			
			else if(j == 5)
			{
				couleur("31");
				printf(" %d ", plateau[i][j]);
				couleur("0");
			}
			
			else if(j == 3)
			{
				printf(" %d ", plateau[i][j]);
				printf("||");
			}
			
			else
			{
				printf(" %d ", plateau[i][j]);
			}
		}
		
		printf("|\n");
	}
	printf("======================\n");
}

void resultat(int bp)
{
	if(bp == 4)
	{
		couleur("31");
		printf("YOU WIN\n");
		couleur("0");
	}
	
	else
	{
		couleur("32");
		printf("YOU LOSE\n");
		couleur("0");
	}
}
