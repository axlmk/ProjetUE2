#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "statique.h"
#include "historique.h"
#include <string.h>


char* nomFichierParDefaut = "/home/exiasaver/Documents/ConsoleSaver/PBM/maison.pbm"; // windows only

void imprimerTableAscii()
{
    unsigned int i =0;
    for(i=128; i < 255; i++)
    {
        if((i%8) == 0)
        {
           printf("\n");
        }
        printf("%d : %c ", (int)i, (char)i);
    }
}

int main(int argc, char** argv)
{
    char* nomFichierHisto = "/home/exiasaver/Documents/ConsoleSaver/PBM/histo.txt";
    Session essai;
    strcpy(essai.nomFichierImage, "Nom_bidon.pbm");
    essai.largeur = 1;
    essai.hauteur = 2;
    essai.positionX = 3;
    essai.positionY = 4;

    char* nomFichierImage = nomFichierParDefaut;
    if(argc > 1)
        nomFichierImage = argv[1]; // <=> *(argv +1)
    ExiaImage imgConsole;
    imgConsole.resX = 80;
    imgConsole.resY = 24;
    allouerImage(&imgConsole);
    ExiaImage img;
    lireFichier(&img, nomFichierImage);

    int posX = imgConsole.resX/2; // centre de console
    int posY = imgConsole.resY/2; // centre de console
    while(1)
    {
        essai.typeLancement = 1 + (abs(rand()) %3);
        majDateSession(&essai);
        enregistrer(&essai, nomFichierHisto);

        initialiserContenu(&imgConsole,' ');
        centrerImageDans(&imgConsole, &img, posX, posY );
        afficherImage(&imgConsole);

        int tab[256], i;
        for (i=0; i<256; i++)
            {
            tab[i]=(char)i;
            }
        char c;
        c = getchar();  // <=> scanf("%c",&c);

        for (i=0; i<256; i++)
        {
            tab[i]=(char)i;
            if (c == tab[i])
            {
                return 0;
            }
        }

    }
}
