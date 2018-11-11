#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


int main()
{
	donnee_t* tete = NULL;	
	donnee_t* premier = (donnee_t*)malloc(sizeof(donnee_t));
	donnee_t* second = (donnee_t*)malloc(sizeof(donnee_t));
	donnee_t* newTete = (donnee_t*)malloc(sizeof(donnee_t));
	
	strcpy(premier->nom, "SC2");
	strcpy(premier->alias, "KINGLOXXY");
	premier->score = 60;
	premier ->next = NULL;
	
	tete = premier;
	
	strcpy(second->nom, "LOL");
	strcpy(second->alias, "MATDREAM");
	second->score = 4;
	second->next = NULL;
	
	premier->next = second;
	
	strcpy(newTete->nom, "CS");
	strcpy(newTete->alias, "JOJO");
	newTete->score = 20;
	
	newTete->next = premier;
	
	tete = newTete;
	
	affichageListe(tete);
	
	return 0;
}


