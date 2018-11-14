#include "master.h"

int main(int argc, char** argv)
{
	int plateau[NB_LIGNES][NB_COLONNES + 2];
	int solution[NB_COLONNES];
	int proposition[NB_COLONNES];
	int bp = 0;
	int mp = 0; 
	int nbcoup = 0;
	
	if(argc > 1) /* initialisation ramdom manuellement */
	{
		srand(atoi(argv[1]));
	}
	
	else
	{
		srand(time(NULL));
	}

	printf("Bienvenue dans le mastermind :\n");

	initialiser_plateau(plateau);
	initialiser_solution(solution);
		
	do
	{
		bp = 0, mp = 0; // remise a zero des valeurs a trouve.
		vocabCouleur();
		saisie(proposition);
		compiler_proposition(proposition, solution, &bp, &mp);
		MajPlateau(plateau, proposition, bp, mp, nbcoup);
		affichagePlateau(plateau);
		nbcoup++;
	
	}while(bp != 4 && nbcoup < 10);
	
	resultat(bp, solution);
	
	return 0;	
}
