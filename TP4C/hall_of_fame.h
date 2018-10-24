#ifndef hall_of_fame_h
#define hall_of_fame_h

#define TAILLE_MAX 50

struct donnee
{
	int score;
	char nom[100];
	char alias[40];
};

typedef struct donnee donnee_t;

void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
int tableauFromFilename(const char* nomFich, donnee_t tab[TAILLE_MAX]);

#endif
