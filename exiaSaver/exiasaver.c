#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include "exiasaver.h"

int chiffreRandom (int n){
    int r;
    srand(time(NULL));  //Initialisation de rand à un endroit aléatoire basé sur l'heure
    r = (rand()%n);     //random entre 0 et n (n exclu)

    return r;
}

char selectionImage (int n){
    int k;
    char c;

    DIR* rep = NULL;
    struct dirent* fichierLu = NULL;
    rep = opendir("CheminDuDossierContenantLesImages");


    if(rep == NULL){ //Si le dossier n'a pas pu être ouvert, fermeture du programme
            exit(1);}


    for(k = 0 ; k < ((rand()%n)+2) ; k++){ /*Après avoir fait un random, parcours les fichiers du dossier
                                                                                jusqu'à tomber sur le Nième fichier dont il renvoie le nom
                                                                                Le "+2" permet de sauter les fichiers "." et ".."*/
        fichierLu = readdir(rep); //On lit le nom du fichier qui vient
    }


    closedir(rep);
    if(closedir(rep) == -1){ //Si le dossier n'a pas pu être fermé correctement, fermeture du programme
        exit(-1);}


    c = (fichierLu->d_name);
    return c;               //On renvoie le nom du fichier désigné par le hasard comme celui devant être affiché
}

    struct tm heure (){
        time_t secondes;    /*time_t est un type de variable qui indique un nombre de secondes*/
        struct tm instant;  /*Une structure tm contient des variables concernant la date et l'heure*/

        time(&secondes);
        instant = *localtime(&secondes);
        return instant;
    }
