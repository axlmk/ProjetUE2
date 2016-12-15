#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include "exiasaver.h"
#include "lireecrire.h"
#include <string.h>


int main(int argc, char *argv[])
{system("clear");

if (argc > 1){
    int k;
    char stat[10];
    strcpy(stat, "-stat");
    if(k = (strcmp(argv[1], stat)) == 0){

    lire();

    }else{

    printf("Veuillez entrer une extension correcte\n");
    }
}else{

    int choix; //Résultat du tirage au sort permettant de choisir entre les 3 écrans

    choix = chiffreRandom(3)+1;
    printf("L'écran choisi est le numéro %d\n",choix);

    //ecrire();


    if(choix == 1){         //Si le résultat du random est 0
        printf("Ecran statique\n");
        char nomDeLImage[25];

        //nomDeLImage = selectionImage(NOMBREDEFICHIERIMAGE)
        sprintf(nomDeLImage, "xxx");

        //--------------------HISTORIQUE----------------------
        ecrire(choix, nomDeLImage);

        //execlp("programmes/statique","statique", "nomImageAAfficher.pbm", NULL);

    }else if(choix == 2){
        printf("Ecran dynamique\n"); //FONCTION DYNAMIQUE
        int di; //Multiplicateur de dimension
        char dyn[3];
       /*struct tm temps;

        temps = heure();*/
        di = chiffreRandom(8);
        sprintf(dyn, "%d", di);
        //---------------------HISTORIQUE---------------------
        ecrire(choix, dyn);


        //execlp("/home/Bureau/Test.txt","Dynamique.txt", Heure, min, sec, dimension, NULL);

    }else if(choix == 3){

        printf("Ecran interractif\n");
        int l, h; //Position en largeur et en hauteur
        char tab[10];

        l = chiffreRandom(82); //Random Largeur

        h = chiffreRandom(24); //Random Hauteur

        sprintf(tab, "%d x %d", l, h);
        //---------------------HISTORIQUE--------------------

        ecrire(choix, tab);
       // execlp("/home/Bureau/Test.txt","Text.txt", , NULL);
    }
}
}

