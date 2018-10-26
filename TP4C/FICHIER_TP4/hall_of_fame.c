#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"

// un petit commentaire ?
void afficherDonnee(FILE * file, donnee_t d) {
   fprintf(file,"%s : %s avec %d\n", d.nom, d.alias, d.score);
}

// un petit commentaire ?
void saisirDonnee(FILE *file, donnee_t * p)
{
	char sscore[100];
	int i = 0;
   fgets(p->nom, 100, file);
   fgets(p->alias, 40, file);
   while(p->nom[i] != '\0')
   {
   		if ( p->nom[i] == '\n')
   			p->nom[i] = '\0';	
   		i++;
   }
   i=0;
   
   while(p->alias[i] != '\0')
   {
   		if ( p->alias[i] == '\n')
   			p->alias[i] = '\0';	
   		i++;
   }
   
   fgets(sscore, 100, file);
   p->score = atoi(sscore);
}


int tableauFromFilename(char* nomF,   donnee_t tab[TAILLE_MAX])
{
	int i = 0;
	FILE* fd = fopen(nomF, "r");
	if ( fd != NULL)
	{
		while(!feof(fd))
		{
			saisirDonnee(fd, &tab[i++]);	
		}
		fclose(fd);
		return i;
	}
	else
	{
		return 0;
	}
}
