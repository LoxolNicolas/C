#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9
#define HORIZ 0
#define VERT 1

void initialiser(int mat[N][N]);
void afficher(int mat[N][N]);
void remplir(int mat[N][N]);
void alea(int mat[N][N]);
int generer(int mat[N][N]);
void saisir(int mat[N][N], int occupe[N][N], int* remplissage);
int tousDifferent(int tab[N]);
int verifierLigneColonne(int mat[N][N], int num, int sens);
int verifieRegion(int mat[N][N], int k, int l);
int verifieGrille(int mat[N][N]);
void reecriture(int mat[N][N], int occupe[N][N]);
void remplitFichier(int mat[N][N]);
