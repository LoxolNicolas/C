#ifndef master_h
#define master_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* DECLARATION DES CONSTANTES SYMBOLIQUES */

#define NB_COLONNES 4
#define NB_LIGNES 10
#define NB_COULEURS 6

#define couleur(param) printf("\033[%sm",param)

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin

typedef struct 
{

} combinaison;

/* DECLARATIONS DES METHODES */

void initialiser_solution(int tabS[NB_COLONNES]);
void initialiser_plateau (int plateau[NB_LIGNES][NB_COLONNES + 2]);
void compiler_proposition(int prop[NB_COLONNES], int sol[NB_COLONNES], int* bp, int* mp); 
void saisie(int prop[NB_COLONNES]);
void MajPlateau(int plateau[NB_LIGNES][NB_COLONNES + 2], int prop[NB_COLONNES], int bp, int mp, int nbcoup);
void affichagePlateau(int plateau[NB_LIGNES][NB_COLONNES +2]);
void resultat(int bp, int solution[NB_COLONNES]);
void vocabCouleur();
void coloration(int cellule);

#endif
