#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdarg.h>

void affiche_Contenu(int nbArg, ...);

int main()
{
    affiche_Contenu(3, ".", "..", "/home/local.isima.fr/niloxol");

    return 0;
}

void affiche_Contenu(int nbArg, ...)
{
    struct dirent* lecture;

	DIR* rep;

    char* directory = NULL;

    va_list liste;

    va_start(liste, nbArg);

    while(nbArg)
    {

        directory = va_arg(liste, char*);

        printf("%s\n", directory);

        rep = opendir(directory);

        while ((lecture = readdir(rep))) 
        {
	        printf("%s\n", lecture->d_name);
	    }
        nbArg--;
    }

    va_end(liste);

	closedir(rep);
}

