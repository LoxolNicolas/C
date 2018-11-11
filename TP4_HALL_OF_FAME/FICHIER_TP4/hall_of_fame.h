#ifndef hall_of_fame_h
#define hall_of_fame_h
#define TAILLE_MAX 50

struct donnee
{
	int score;
	char nom[100];
	char alias[40];
	struct donnee* next;
};
typedef struct donnee donnee_t;

/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
int tableauFromFilename(char* nomF,   donnee_t tab[TAILLE_MAX]);
void afficherListe(donnee_t* tete);
donnee_t* creerElement();
void insererListe(donnee_t** tete, donnee_t* newF);
void libererListe(donnee_t* tete);
void modifierElement(donnee_t** tete);
void menu(donnee_t** tete);

#endif
