#include<stdio.h>

void saisir(char* s)
{
  printf("Saisir une chaine\n");
  scanf("%s", s);
}

int main()
{
  char* s;

  printf("Entrer votre prenom. ");
  saisir(s);
  printf("Bonjour %s!\n", s);

  if (s =="ddd") printf("bizarre \n");

  return 0;
}
