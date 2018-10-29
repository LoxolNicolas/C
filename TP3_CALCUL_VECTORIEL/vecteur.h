// on appelle cette constante symbolique un gardien, cela permet de s'assurer que ce fichier
// ne sera pas inclus de maniere recursive
#ifndef C3__VECTEUR_H
#define C3__VECTEUR_H

#include <stdio.h>

// prototypes incomplets des fonctions a coder
void vecteurToFile(FILE* f, float* vec, int ordre);
float* vecteurFromFileByName(const char* nom, int* ordre);
float produitScalaire(float* x, float* y, int ordre);
void libererVecteur(float** vec);
void matriceToFile(FILE* f, float** m, int n);
float** matriceFromFileName(const char* nom, int ordre); 


#endif
