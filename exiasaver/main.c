#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "exiaImage.h"

int main()
{

    ExiaImage imgConsole;
    imgConsole.resX = 80;
    imgConsole.resY = 24;
    allouerImage(&imgConsole);
    ExiaImage img;
    lireFichier(&img, "C:/Users/dewid/Desktop/screensav/exiasaver/PBM/maison.pbm" );

    int posX = imgConsole.resX/2; // centre de console
    int posY = imgConsole.resY/2; // centre de console
    while(1)
    {
        initialiserContenu(&imgConsole,' ');
        centrerImageDans(&imgConsole, &img, posX, posY );
        afficherImage(&imgConsole);
        char c;
        c = getchar();  // <=> scanf("%c",&c);
        if(c=='h')      // haut
            posY--;
        if(c=='b')      // bas
            posY++;
        if(c=='d')      // droite
            posX++;
        if(c=='g')      // gauche
            posX--;
    }
    return 0;
}
