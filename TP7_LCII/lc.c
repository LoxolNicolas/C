#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Cellule
{
    char ligne[255];
    struct Cellule* suiv;
}Cellule_t;

typedef struct Liste
{
    Cellule_t* tete;
    Cellule_t* fin;
}Liste_t;

struct Liste* init();
void affiche(Liste_t* l);
void inserer_Tete(Liste_t* l, char* ch);
void inserer_Fin(Liste_t* l, char* ch);
//void WriteFromFile(const char* nomF, Liste_t* l);
//void ReadFromFile(const char* nomF, );

int main(int argc, char** argv)
{
    Liste_t* l = init();

    if(argc != 1)
    {
       
    }

    else
    {
        char buffer[255];

        while(fgets(buffer, 255, stdin))
        {
            inserer_Fin(l, buffer);
             
        }

        affiche(l);
    }
    
    return 0;
}

struct Liste* init()
{
    Liste_t* l = (Liste_t*)malloc(sizeof(struct Liste));

    if(l == NULL)
    {
        exit(EXIT_FAILURE);
    }

    l->tete = NULL;
    l->fin = NULL;

    return l;
}

void affiche(Liste_t* l)
{
    struct Cellule* element = l->tete;

    while(element != NULL)
    {
        printf("%s", element->ligne);
        element = element -> suiv;
    }
}

void inserer_Tete(Liste_t* l, char* ch)
{
    struct Cellule* element = (struct Cellule*)malloc(sizeof(struct Cellule));

    if(element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->suiv = l->tete;
    strcpy(element->ligne, ch);

    l->tete = element;
}

void inserer_Fin(Liste_t* l, char* ch)
{
    struct Cellule* element = (struct Cellule*)(malloc(sizeof(struct Cellule)));

    if(element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(element->ligne, ch);
    (l->fin)->suiv = element;
    element->suiv = NULL;

    l->fin = element;
}

void WriteFromFile()
{

}

void ReadFromFile()
{

}
