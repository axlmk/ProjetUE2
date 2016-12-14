#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include "exiasaver.h"

int main()
{
    int choix; //Résultat du tirage au sort permettant de choisir entre les 3 écrans


    choix = chiffreRandom(3);
    printf("L'écran choisi est le numéro %d\n",choix);

    if(choix == 0){         //Si le résultat du random est 0
        printf("Ecran statique");
        char nomDeLImage;

        nomDeLImage = selectionImage(NOMBREDEFICHIERIMAGE)

        execlp("/home/Bureau/Test.txt","Text.txt", NULL);

    }else if(choix == 1){

        printf("Ecran dynamique"); //FONCTION DYNAMIQUE
        int di; //Multiplicateur de dimension
        struct tm temps;

        temps = heure();
        di = chiffreRandom(8);

    }else if(choix == 2){

        printf("Ecran interractif");
        int l, h; //Position en largeur, en hauteur et direction

        l = chiffreRandom(82); //Random Largeur

        h = chiffreRandom(24); //Random Hauteur

    }


    /*----------------------------APPEL HISTORIQUE-----------------------------*/


}
