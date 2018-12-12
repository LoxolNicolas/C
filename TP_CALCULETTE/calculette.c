#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef enum ope
{
    ID, SIN, COS, LOG, EXP, NONE
} OP;

const char * OPER_NAMES[] = { "x", "sin(x)", "cos(x)", "log(x)", "exp(x)", NULL };

OP identification(char* ch);
double evaln(double x, enum ope operation);
void calcul(double a, double b, double delta, enum ope operation);

int main()
{
    double a, b, delta;
    char nomOperation[10];
    char buffer[10];

    printf("Saisir fonction, a, b ,delta: \n");

    fgets(nomOperation, 10, stdin);
    nomOperation[strlen(nomOperation)-1] = '\0';
    fgets(buffer, 10, stdin);
    a = atof(buffer);
    fgets(buffer, 10, stdin);
    b = atof(buffer);
    fgets(buffer, 10, stdin);
    delta = atof(buffer);

    calcul(a, b, delta, identification(nomOperation));

    return 0;
}

OP identification(char* ch)
{
    int i = 0;
    int TROUVE = FALSE;
    enum ope operation = ID; 
    
    while((OPER_NAMES[i] != NULL) && (TROUVE != TRUE))
    {
        if(strcmp(ch, OPER_NAMES[i]) == 0)
        {
            TROUVE = TRUE;
        }

        operation++;

        i++;
    }

    return --operation;
}

double evaln(double x, enum ope operation)
{
    double retour;

    switch(operation)
    {
        case ID:
            retour = x;
            break;
        
        case SIN:
            retour = sin(x);
            break;
        
        case COS:
            retour = cos(x);
            break;

        case LOG:
            retour = log(x);
            break;

        case EXP:
            retour = exp(x);
            break;
    
        default:
            printf("ERREUR MAUVAISE OPERATION");
            exit(EXIT_FAILURE);
            break;
    }

    return retour;
}

void calcul(double a, double b, double delta, enum ope operation)
{
    for(a; a < b; a+=delta)
    {
        printf("%f\n", evaln(a, operation));
    }
}