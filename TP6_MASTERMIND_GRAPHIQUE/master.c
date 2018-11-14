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
		for(j = 0; j < (NB_COLONNES + 2); j++)
		{
			plateau[i][j] = 0;
		}
	}
}

void compiler_proposition(int prop[NB_COLONNES], int sol[NB_COLONNES], int* bp, int* mp) 
{
	int i, j;
	
	int tabCorres[NB_COLONNES] = {0, 0, 0, 0};
	int tabCorresP[NB_COLONNES] = {0, 0, 0, 0};
	
	for(i = 0; i < NB_COLONNES; i++)
	{
		if(prop[i] == sol[i])
		{
			(*bp)++;
			tabCorres[i] = 1;
			tabCorresP[i] = 1;
		}
	}
	
	for(i = 0; i < NB_COLONNES; i++)
	{
		for(j = 0; j < NB_COLONNES; j++)
		{
			if(prop[i] == sol[j])
			{
				if(tabCorres[j] == 0 && tabCorresP[i] == 0)
				{
					if(i != j)
					{
						(*mp)++;
						tabCorres[j] = 1;
						tabCorresP[i] = 1;
					}
				}
			}
		}
	}	
}

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

	for(i = 0; i < NB_LIGNES; i++)
	{
		printf("|");

		for(j = 0; j < (NB_COLONNES + 2); j++)
		{	

			coloration(plateau[i][j]);

			switch(j)
			{
				case 3:
					printf(" %d ", plateau[i][j]);
					couleur("0");
					printf("||");
					break;

				case 4:
					couleur("32");
					printf(" %d ", plateau[i][j]);
					couleur("0");
					break;

				case 5:
					couleur("31");
					printf(" %d ", plateau[i][j]);
					couleur("0");
					break;

				default:
					printf(" %d ", plateau[i][j]);
					couleur("0");
					break;
			}
		}
		
		printf("|\n");
	}

	printf("======================\n");
}

void resultat(int bp, int sol[NB_COLONNES])
{
	if(bp == 4)
	{
		couleur("32");
		printf("YOU WIN\n");
		couleur("0");
	}
	
	else
	{
		couleur("31");
		printf("YOU LOSE\n");
		couleur("0");
		
		printf("La solution etait : %d %d %d %d\n", sol[0], sol[1], sol[2], sol[3]);
	}
}

void vocabCouleur()
{
	printf("1-Jaune\n");
	printf("2-Rouge\n");
	printf("3-Vert\n");
	printf("4-Blanc\n");
	printf("5-Rose\n");
	printf("6-Cyan\n");
}

void coloration(int cellule)
{
	switch(cellule)
	{
		case 1:
			couleur("33");
			break;
					
		case 2:
			couleur("31");
			break;
					
		case 3:
			couleur("32");
			break;
					
		case 4:
			couleur("0");
			break;
					
		case 5: 
			couleur("35");
			break;
					
		case 6:
			couleur("36");
			break;
	}	
}

void afficherEcran(SDL_Renderer* renderer, SDL_Surface* image, SDL_Rect* rect)
{
	/* couleur de fond */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_Texture  *avatar;

	int i, j;

	avatar = SDL_CreateTextureFromSurface(renderer, image);

	rect->x = 0;
	rect->y = 0;
	rect->w = 500;
	rect->h = 800;

	SDL_RenderCopy(renderer, avatar, NULL, rect);

	for(j = 0; j < 10; j++)
	{
		for(i = 0; i < 4; i++)
		{
			SDL_Rect rect;
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 200);
			rect.y = (j*60) + 75;
			rect.x = (i*50) + 100;
			rect.w = 25;
			rect.h = 25;
			SDL_RenderFillRect(renderer, &rect );
		}
	}

	SDL_RenderPresent(renderer);

	/* L'image a ete copiee dans le renderer qui sera plus tard affiche a l'ecran */	
}