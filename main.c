#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_MAX_CHAINE 50
int main()
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX_CHAINE] = " ";

    fichier = fopen("test.txt", "r");

    if(fichier != NULL){

        while (fgets(chaine, TAILLE_MAX_CHAINE, fichier) != NULL){

            printf("%s", chaine);

        }

        fclose(fichier);

    }
    return 0;
}
