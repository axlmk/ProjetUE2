#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lireecrire.h"

void ecrire(){
    struct tm heure();

    FILE* fichier = NULL; //Initialisation pointeur fichier
    //char texte;
    struct tm time;

    time = heure();

    fichier = fopen("test.txt", "a");

    if (fichier != NULL){
        //texte = "Allo ?";

        fprintf(fichier, "%d/%d/%d ; %d:%d:%d ; %d ; %d.pbm\n", time.tm_mday, time.tm_mon +1, time.tm_year +1900, time.tm_hour, time.tm_min, time.tm_sec);

        fclose(fichier);

    }else{

        printf("Impossible d'ouvrir le fichier");

    }

    return 0;
}

struct tm heure (){
        time_t secondes;    /*time_t est un type de variable qui indique un nombre de secondes*/
        struct tm instant;  /*Une structure tm contient des variables concernant la date et l'heure*/

        time(&secondes);
        instant = *localtime(&secondes);
        return instant;
}
