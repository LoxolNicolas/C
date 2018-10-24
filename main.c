#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"

int main()
{
	
	donnee_t* tete = NULL;
	
	donnee_t* first = (donnee_t*)malloc(sizeof(donnee_t));
	donnee_t* second = (donnee_t*)malloc(sizeof(donnee_t));
	donnee_t* newfirst = (donnee_t*)malloc(sizeof(donnee_t));
	
	strcpy(first->nom,"CODBO4");
	strcpy(first->alias,"alexis");
	first->score = 24;
	first -> next = NULL;
	tete = first;
	
	strcpy(second->nom,"Minecraft");
	strcpy(second->alias,"armen");
	second->score = 100;
	second -> next = NULL;
	first->next = second;
	
	strcpy(newfirst->nom,"CS");
	strcpy(newfirst->alias,"loxol");
	newfirst->score = 10;
	newfirst -> next = first;
	tete = newfirst;
	
	afficherListe(tete);
	menu(&tete);
	afficherListe(tete);
	libererListe(tete);
	
	return 0;
}

void afficherListe(donnee_t* tete)
{
	donnee_t* tmp = tete;

	while(tmp != NULL)
	{
		printf("%s sur le jeu %s a un score de %d \n", tmp->alias, tmp->nom, tmp->score);
		tmp = tmp->next;
	}
}

donnee_t* creerElement()
{
	donnee_t* retour = (donnee_t*)malloc(sizeof(donnee_t));
	printf("Quel est le nom du jeu ?\n");
	scanf("%s",retour->nom);
	printf("Quel est le nom du joueur ?\n");
	scanf("%s",retour->alias);
	printf("Quel est le score\n");
	scanf("%d",&(retour->score));
	
	return retour;
}
void insererListe(donnee_t** tete, donnee_t* newF)
{
	newF -> next = *tete;
	*tete = newF;
}

void libererListe(donnee_t* tete)
{
	donnee_t* tmp = tete;
	donnee_t* courant;
	while(tmp)
	{
		courant = tmp -> next;
		free(tmp);
		tmp = courant;
		
	}
	tete = NULL;
}

void modifierElement(donnee_t** tete)
{
	donnee_t* tmp = *tete;
	int trouve = 0;
	
	char v[100];
	
	printf("Saisir le nom du jeu a modifier : ");
	scanf("%s", v);
		
	while(tmp!= NULL && !trouve)
	{
		if(!strcmp(tmp->nom, v))
		{
			printf("Saisir le nouveau nom :");
			scanf("%s", tmp->alias);
			trouve = 1;
		}
		
		tmp = tmp->next;
	}
}

void menu(donnee_t** tete)
{
	int continu = 1;
	while(continu)
	{
		int choice;
		printf(" --------------MENU--------------\n");
		printf(" 1 - Afficher la liste\n");
		printf(" 2 - Insérer élément en tête\n");
		printf(" 3 - Quitter\n");
		printf(" 4 - Modifier un élément\n");
		printf(" 5 - Lire a partir d'un fichier\n");
		printf(" 6 - Sauvegarder dans un fichier\n");
		printf(" --------------------------------\n");
		scanf("%d%*c",&choice);
	
		switch(choice)
		{
			case 1 :
				afficherListe(*tete);
				break;
			
			case 2 :
				insererListe(tete, creerElement());
				break;
			
			case 3 :
				continu = 0;
				break;
				
			case 4 :
				modifierElement(tete);
				break;
				
			case 5 :
				break;
			case 6 :
				break;
			default :
				break;
		}
	}
}
