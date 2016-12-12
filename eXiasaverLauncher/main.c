#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>

int main()
{
    int r; //R�sultat du tirage au sort entre les 3 �crans

    //FAIRE FONCTION POUR HASARD

    srand(time(NULL));  //Initialisation de rand � un endroit al�atoire bas� sur l'heure
    r = (rand()%3);     //random entre 0 et 3 (3 exclu)
    printf("%d\n",r);

    if(r == 0){         //Si le r�sultat du random est 0
        printf("Ecran statique");

        //FAIRE FONCTION POUR SELECTION IMAGE
        int n;

        DIR* rep = NULL;
        struct dirent* fichierLu = NULL;

        rep = opendir("CheminDuDossierContenantLesImages");
        if(rep == NULL){ //Si le dossier n'a pas pu �tre ouvert, fermeture du programme
            exit(1);}

        for(;n=0 ; n < ((rand()%nombredefichierIMAGEdansledossier)+2) ; n++){ /*Apr�s avoir fait un random, parcours les fichiers du dossier
                                                                                jusqu'� tomber sur le Ni�me fichier dont il renvoie le nom
                                                                                Le "+2" permet de sauter les fichiers "." et ".."*/
            fichierLu = readdir(rep); //On lit le nom du fichier qui vient
        }

        closedir(rep);
        if(closedir(rep) == -1){ //Si le dossier n'a pas pu �tre ferm� correctement, fermeture du programme
            exit(-1)}
        return(fichierLu->d_name) //On renvoie le nom du fichier d�sign� par le hasard comme celui devant �tre affiche

    }else if(r == 1){
        printf("Ecran dynamique"); //FONCTION DYNAMIQUE
        int di; //Multiplicateur de dimension
        // DEPLACER FONCTION
        char heure (){
            time_t secondes;    /*time_t est un type de variable qui indique un nombre de secondes*/
            struct tm instant;  /*Une structure tm contient des variables concernant la date et l'heure*/

            time(&secondes);
            instant = *localtime(&secondes);
            return instant;
        }

        srand(time(NULL));  //Initialisation de rand � un endroit al�atoire bas� sur l'heure
        di = (rand()%7);

    }else if(r == 2){
        printf("Ecran interractif");
        int l, h, d; //Position en longueur, en hauteur et direction

        srand(time(NULL));  //Random Largeur
        l = (rand()%82); //De 0 � 81 si le 0 existe, � modifier sinon !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        srand(time(NULL));  //Random Hauteur
        h = (rand()%24); //De 0 � 23 si le 0 existe, � modifier sinon !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        srand(time(NULL));  //Random Direction
        d = (rand()%3); //0 vers le haut, 1 vers le bas, 2 vers la gauche et 3 vers la droite
    }
}
