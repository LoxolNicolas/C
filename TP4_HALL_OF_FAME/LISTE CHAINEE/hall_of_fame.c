#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"

void afficherDonnee(FILE * file, donnee_t d) 
{
   fprintf(file, "%s : %s avec %d\n", d.nom, d.alias, d.score);
}

void saisirDonnee(FILE *file, donnee_t * p)
{
	char sscore[100];
	
	int i = 0,j = 0;
	
	fgets(p->nom, 100, file);
	fgets(p->alias, 40, file);
	fgets(sscore, 100, file);
	p->score = atoi(sscore); 
	
	while(p->nom[i] != '\0')
	{
		if(p->nom[i] == '\n')
		{
			p->nom[i] = '\0';
		}
		i++;
	}
	
	while(p->alias[j] != '\0')
	{
		if(p->alias[j] == '\n')
		{
			p->alias[j] = '\0';
		}
		j++;
	}
}

int tableauFromFilename(const char* nomFich, donnee_t tab[TAILLE_MAX])
{
	FILE* f = fopen(nomFich, "r");
	int i = 0;
	
	if(f)
	{
	
		while(!feof(f))
		{
			saisirDonnee(f, &tab[i]);
			i++;
		}
	
		fclose(f);
		
		return i;
	}
	
	else
	{
		return 0;
	}
}

void affichageListe(donnee_t* tete)
{
	donnee_t* tmp = tete;
	
	while(tmp != NULL)
	{
		printf("%s sur le jeu de %s a %d\n", tmp->alias, tmp->nom, tmp->score);
		tmp = tmp->next;
	}
}
