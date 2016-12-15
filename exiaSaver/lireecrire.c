#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lireecrire.h"
#include "exiasaver.h"
#define TAILLE_MAX_CHAINE 50

void ecrire(int type, char info[]){
    struct tm heure();

    FILE* fichier = NULL; //Initialisation pointeur fichier
    //char texte;
    struct tm time;

    time = heure();

    fichier = fopen("data/historique/historique.txt", "a");

    if (fichier != NULL){
        //texte = "Allo ?";

        fprintf(fichier, "%d/%d/%d ; %d:%d:%d ; %d ; %s\n", time.tm_mday, time.tm_mon +1, time.tm_year +1900, time.tm_hour, time.tm_min, time.tm_sec, type, info);

        fclose(fichier);

    }else{

        printf("Impossible d'ouvrir le fichier");

    }
    if(type == 1){
        fichier = fopen("data/historique/statique.txt", "a");
        if (fichier != NULL){
            fprintf(fichier, "%d/%d/%d ; %d:%d:%d ; %d ; %s\n", time.tm_mday, time.tm_mon +1, time.tm_year +1900, time.tm_hour, time.tm_min, time.tm_sec, type, info);

            fclose(fichier);
        }
    }else if(type == 2){
        fichier = fopen("data/historique/dynamique.txt","a");
        if (fichier != NULL){
            fprintf(fichier, "%d/%d/%d ; %d:%d:%d ; %d ; %s\n", time.tm_mday, time.tm_mon +1, time.tm_year +1900, time.tm_hour, time.tm_min, time.tm_sec, type, info);

            fclose(fichier);
        }
    }else if(type == 3){
        fichier = fopen("data/historique/interactif.txt","a");
        if (fichier != NULL){
            fprintf(fichier, "%d/%d/%d ; %d:%d:%d ; %d ; %s\n", time.tm_mday, time.tm_mon +1, time.tm_year +1900, time.tm_hour, time.tm_min, time.tm_sec, type, info);

            fclose(fichier);
        }
    }
}

void lire(){
    int r; //Réponse
    printf("Souhaitez vous un affichage par ordre chronologique\n ou par type d'ecran ?\n1/Chronologique\n2/Type\n");
    scanf("%d", &r);

    FILE* fichier = NULL;
    char chaine[TAILLE_MAX_CHAINE] = " ";

    if (r == 1){
        fichier = fopen("data/historique/historique.txt", "r");

        if(fichier != NULL){

            while (fgets(chaine, TAILLE_MAX_CHAINE, fichier) != NULL){

                printf("%s", chaine);

            }

            fclose(fichier);

        }
    }else if(r == 2){
        fichier = fopen("data/historique/statique.txt","r");
        if (fichier != NULL){
            while (fgets(chaine, TAILLE_MAX_CHAINE, fichier) != NULL){
                printf("%s", chaine);
            }
            fclose(fichier);
        }
        printf("\n");
        fichier = fopen("data/historique/dynamique.txt", "r");
        if (fichier != NULL){
            while (fgets(chaine, TAILLE_MAX_CHAINE, fichier) != NULL){
                printf("%s", chaine);
            }
            fclose(fichier);
        }
        printf("\n");
        fichier = fopen("data/historique/interactif.txt","r");
        if (fichier != NULL){
            while (fgets(chaine, TAILLE_MAX_CHAINE, fichier) != NULL){
                printf("%s", chaine);
            }
            fclose(fichier);
        }
    }
}

/*struct tm heure (){
        time_t secondes;    /*time_t est un type de variable qui indique un nombre de secondes*
        struct tm instant;  /*Une structure tm contient des variables concernant la date et l'heure*

        time(&secondes);
        instant = *localtime(&secondes);
        return instant;*/
//}
