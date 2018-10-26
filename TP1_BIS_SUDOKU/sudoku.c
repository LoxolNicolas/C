#include "sudoku.h"

int main()
{
	int mat[N][N];
	int occupe[N][N] = {0};
	int remplissage = 0;

	printf("SUDOKU\n");

	srand(time(NULL));

	initialiser(mat);

	remplir(mat);
	alea(mat);

	//remplitFichier(mat); REMPLIT VIA FICHIER TXT

	remplissage = (N*N) - generer(mat);

	reecriture(mat, occupe);
	afficher(mat);

	while(!verifieGrille(mat))
	{
		saisir(mat, occupe, &remplissage);
		afficher(mat);
	}

	return 0;
}

void initialiser(int mat[N][N])
{
	int i,j;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			mat[i][j] = 0;
		} 
	}
}

void afficher(int mat[N][N])
{
	int i,j;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d  ", mat[i][j]);
		} 
		printf("\n");
	}
}

void remplir(int mat[N][N])
{
	int i, j;

	for(j = 0; j < N; j++)
	{
  		for(i = 0; i < N; i++)
		{
			mat[j][i] = (i + j * 3 + j / 3) % 9 + 1;
		}
      
	}
}

int generer(int mat[N][N])
{
	int i,j;
	int non_nul = 0;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(mat[i][j] != 0)
			{
				non_nul++;
			}
		} 
	}

	return non_nul;
}

void saisir(int mat[N][N], int occupe[N][N], int* remplissage)
{
	int i, j, val;

	printf("Saisir i et j : ");
	scanf("%d %d", &i, &j);

	printf("Saisir la valeur de la case (%d, %d) : ", i, j);
	scanf("%d", &val);

	if((i >= 0 && i <= 9) && (j >= 0 && j <= 9) && (val > 0) && (occupe[i][j] == 0))
	{
		if(mat[i][j] == 0)
		{
			mat[i][j] = val;
			(*remplissage)++;
		}

		else
		{
			printf("Cette case est deja occupe\n");
		}
	}

	else
	{
		printf("Indice ou valeur saisie incorrecte\n");
	}
}

int tousDifferent(int tab[N])
{
	int i,j;
	int dif = 1;

	for(i = 0; i < N - 1; i++) // PAS OPTI FAIRE AVEC WHILE POUR OPTIMISER
	{
		for(j = i + 1; j<N; j++)
		{
			if(tab[i] == tab[j] || tab[i] == 0)
			{
				dif = 0;
			}
		}
	}

	return dif;
}

int verifierLigneColonne(int mat[N][N], int num, int sens)
{
	int i;
	int dif;

	int tab[N];	

	if(sens == HORIZ)
	{
		for(i = 0; i < N; i++)
		{
			tab[i] = mat[num][i]; 
		}
	}
	
	else
	{
		for(i = 0; i < N; i++)
		{
			tab[i] = mat[i][num];
		}
	}

	dif = tousDifferent(tab);

	return dif;
}

int verifieRegion(int mat[N][N], int k, int l)
{
	int i, j, i1, j1;
	int dif;
	int indTab = 0;

	int tab[N];
	
	switch(k)
	{
		case 0:
			i1 = 0;
			break;

		case 1:
			i1 = 3;
			break;

		case 2:
			i1 = 6;
			break;
	}

	switch(l)
	{
		case 0:
			j1 = 0;
			break;

		case 1:
			j1 = 3;
			break;

		case 2:
			j1 = 6;
			break;
	}

	for(i = i1; i < (i1+3); i++)
	{
		for(j = j1; j < (j1+3); j++)
		{
			tab[indTab] = mat[i][j];
			indTab++;
		}
	}

	dif = tousDifferent(tab);

	return dif;
}

int verifieGrille(int mat[N][N])
{
	int i,j;
	int sommeRegion = 0;

	for(i = 0; i<3; i++)
	{
		for(j = 0; j<3; j++)
		{
			sommeRegion += verifieRegion(mat, i ,j);
		}
	}

	return (sommeRegion == 9);
}

void alea(int mat[N][N])
{
	int i;
	int indLigne, indColonne;

	int nbValeurAlea = rand() % 15;

	for(i = 0; i < nbValeurAlea; i++)
	{
		indLigne = rand() % 10;
		indColonne = rand() % 10;

		mat[indLigne][indColonne] = 0;
	}
}

void reecriture(int mat[N][N], int occupe[N][N])
{
	int i,j;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(mat[i][j] != 0)
			{
				occupe[i][j] = 1;
			}

			else
			{
				occupe[i][j] = 0;
			}
		}
	}
}

void remplitFichier(int mat[N][N])
{
	FILE* fichier = fopen("sudoku.txt", "r");
	int i = 0, j = 0;
	char nbAct = 0;

	if(fichier)
	{
		nbAct = fgetc(fichier);

		while(nbAct != EOF)
		{		
			if(nbAct == ' ')
			{
				i++;
			}

			else if(nbAct == '\n')
			{
				j++;
				i = 0;
			}

			else
			{
				mat[i][j] = nbAct - 48;
			}

			nbAct = fgetc(fichier);
		}

		fclose(fichier);
	}

	else
	{
		printf("Fichier invalide");
	}
}
