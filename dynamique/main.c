#include <stdio.h>
#include <stdlib.h>
#include "header/traitementPBM.h"
#include "header/traitementStructure.h"
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>

#define N 3

struct tm heure (){
        time_t secondes;
        struct tm instant;

        time(&secondes);
        instant = *localtime(&secondes);
        return instant;
}

int main(int ar)
{

    while(1){

        system("clear");
        int x = 4;
        int y = 7;
        int a = 0;
        int b = 0;
        int i = 0;

        struct tm horaire;
        horaire = heure();

        fichierPBM fHeu1;
        fichierPBM fHeu2;
        fichierPBM fMin1;
        fichierPBM fMin2;
        fichierPBM fSec1;
        fichierPBM fSec2;
        fichierPBM fPoint;

        for (; a <= horaire.tm_hour; a+=10)
        {
            i++;
        }

        fHeu1 = creeStructure(i - 1);
        fHeu1 = changerStructure(fHeu1);
        fHeu1 = changeTaillePBM(fHeu1, x, y);
        fHeu2 = creeStructure(horaire.tm_hour - (i - 1)*10);
        fHeu2 = changerStructure(fHeu2);
        fHeu2 = changeTaillePBM(fHeu2, x, y);
        fHeu1 = addition(fHeu1, fHeu2);

        fPoint = creeStructure(10);
        fPoint = changerStructure(fPoint);
        fPoint = changeTaillePBM(fPoint, x, y);
        fHeu1 = addition(fHeu1, fPoint);

        i = 0;
        for (a = 0; a <= horaire.tm_min ; a+=10)
        {
            i++;
        }
        fMin1 = creeStructure(i - 1);
        fMin1 = changerStructure(fMin1);
        fMin1 = changeTaillePBM(fMin1, x, y);
        fMin2 = creeStructure(horaire.tm_min - (i-1)*10);
        fMin2 = changerStructure(fMin2);
        fMin2 = changeTaillePBM(fMin2, x, y);
        fMin1 = addition(fMin1, fMin2);
        fMin1 = addition(fHeu1, fMin1);

        fPoint = creeStructure(10);
        fPoint = changerStructure(fPoint);
        fPoint = changeTaillePBM(fPoint, x, y);
        fMin1 = addition (fMin1, fPoint);

        i = 0;
        for (a = 0; a <= horaire.tm_sec ; a+=10)
        {
            i++;
        }
        fSec1 = creeStructure(i - 1);
        fSec1 = changerStructure(fSec1);
        fSec1 = changeTaillePBM(fSec1, x, y);
        fSec2 = creeStructure(horaire.tm_sec - (i-1)*10);
        fSec2 = changerStructure(fSec2);
        fSec2 = changeTaillePBM(fSec2, x, y);
        fSec1 = addition(fSec1, fSec2);
        fSec1 = addition(fMin1, fSec1);

        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        int larg = ((w.ws_col / 2) -fSec1.largeur);
        int haut = ((w.ws_row - fSec1.hauteur) / 2);
        afficheTableau(fSec1, haut, larg);

        int j;

        for(j = 0; j < ((w.ws_row - fSec1.hauteur) / 2); j++)
        {
            printf("\n");
        }
        for(j = 0; j < ((w.ws_col - 48) / 2); j++)
        {
            printf(" ");
        }

        printf("Cet ecran sera actualise dans quelques secondes "); //48
        fflush(stdout);
        sleep(1);

        i = 0;
        do
        {
            printf(". ");
            fflush(stdout);
            i++;
            sleep(1);
        }while(i < N - 1);
        printf("\n");
    }

    return 0;
}
