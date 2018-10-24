#include "vecteur.h"
#include<stdlib.h>

// definition des fonctions declarees dans vecteur.h


void vecteurToFile(FILE* f, float* vec, int ordre) 
{
	int i;
	
	fprintf(f, "%s", "[ ");
	for(i = 0; i < ordre; i++)
	{
		fprintf(f, "%.3f ", vec[i]);
	}	
	fprintf(f, "%s", "]");
}



float* vecteurFromFileByName(const char* nom, int* ordre) 
{
	float* retour = NULL;
	int i;
	FILE* f = fopen(nom, "r");
	
	if(f)
	{
		char buffer[5];
		
		fscanf(f, "%s", buffer);
		
		(*ordre) = atoi(buffer);
	
		retour = (float*) malloc(sizeof(float) * (*ordre));
		
		for(i = 0; i < (*ordre); i++)
		{
			if(!feof(f))
			{
				fscanf(f, "%f", &(retour[i]));
			}
			else
			{
				libererVecteur(&retour);
				retour = NULL;
			}
		}
		
		fclose(f);
	}

	return retour;
}



float produitScalaire(float* x, float* y, int ordre) 
{
	float retour = 0;
	int i;
	
	for(i = 0; i < ordre; i++)
	{
		retour += (x[i] * y[i]);
	}

    return retour;
} 

void libererVecteur(float** vec)
{
	free(*vec);
}

void matriceToFile(FILE* f, float** m, int n)
{
	int i, j;
	
	fprintf(f, "%d\n", n);
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			fprintf(f, "%.1f ", m[i][j]);
		}
		fprintf(f, "%s", "\n");
	}	

}

float** matriceFromFileName(const char* nom, int ordre)
{
	float** retour = NULL;
	int i,j,k;
	FILE* f = fopen(nom, "r");
	
	if(f)
	{
		char buffer[5];
		
		fscanf(f, "%s", buffer);
		
		ordre = atoi(buffer);
	
		retour = (float**) malloc(sizeof(float*) * (ordre));
		
		for(k = 0; k < ordre; k++)
		{
			retour[k] = (float*) malloc(sizeof(float) * (ordre));
		}
		
		for(i = 0; i < ordre; i++)
		{
			for(j = 0; j < ordre; j++)
			{
				if(!feof(f))
				{
					fscanf(f, "%f", &(retour[i][j]));
				}
				else
				{
					for(k = 0; k < ordre; k++)
					{
						free(retour[k]);
					}
					
					free(retour);
					
					retour = NULL;
				}
			}
		}
		
		fclose(f);
	}

	return retour;
}
