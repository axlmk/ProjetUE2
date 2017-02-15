#include "exiaImage.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

void    allouerImage(ExiaImage* img)                                  // alloue le contenu en foction de la taille (resX,resY)
{
    int tailleContenu = img->resX*img->resY * sizeof(char);
    img->contenu = (char *)malloc(tailleContenu);
}

void    libererImage(ExiaImage* img)                                   // libere le contenu
{
    free(img->contenu);
    img->contenu = 0;
}

void    initialiserContenu(ExiaImage* img, char c)                     // remplit le contenu avec le caracter c
{
    // memset(img->contenu,c, img->resX*img->resY );
    int i,j;
    for(i=0; i< img->resY; i++)
        for(j=0; j< img->resX; j++)
            ecrirePixel(img, i, j, c);
}

#define MAX_COL 500
#define VIDE    ' '
#define PLEIN   (char)219

void  lireFichier(ExiaImage* img, char* nomFichierPBM)                // lire le fichier dansla structure ExiaImage
{
    FILE* f = fopen(nomFichierPBM,"r");
    int typeLu      = 0;    // false
    int TailleLue   = 0;
    int numeroLigneLue = 0;
    do
    {
        char ligne[MAX_COL];
        fgets(ligne, MAX_COL, f);   // lecture de la ligne
        if(feof(f))                 // fin de fichier ?
            return;
        if(ligne[0] != '#')         // si la ligne n'est pas un commentaire
        {
            if(!typeLu)
            {
                sscanf(ligne,"P%d",&(img->type));
                typeLu = 1;
                if(img->type != 1)
                {
                    printf("type du fichier %s : %d non supporté", nomFichierPBM, img->type );
                    exit(0);
                }
            }
            else if(!TailleLue)
            {
                sscanf(ligne,"%d %d", &(img->resX), &(img->resY));
                allouerImage(img);
                TailleLue = 1;
            }
            else // on lit une ligne du contenu
            {
                int posSuivante = 0;
                int j;
                for(j=0; j< img->resX; j++)
                {
                    int val=0;
                    sscanf(&ligne[posSuivante], "%d", &val);
                    char aEcrire = (val==0) ? VIDE : PLEIN;
                    ecrirePixel(img, numeroLigneLue, j, aEcrire);
                    posSuivante += strcspn(&ligne[posSuivante], " ");            // recherche prochain blanc
                    posSuivante += strcspn(&ligne[posSuivante], "0123456789");   // recherche prochain chiffre
                }
                numeroLigneLue++;
            }
        }
    } while(1);
}

int Position(ExiaImage* img, int i, int j)
{
    while(i<0)
        i += img->resY;
    while(j<0)
        j += img->resX;
    i = i % (img->resY);
    j = j % (img->resX);

    return i*img->resX+j;
}

char    lirePixel(ExiaImage* img, int i, int j)                        // retourne le pixel de coordonnees (i,j)
{
    int pos = Position(img, i, j);
    return img->contenu[pos];
}

void    ecrirePixel(ExiaImage* img, int i, int j, char c)               // écrit c dans le pixel (i,j)
{
    int pos = Position(img, i, j);
    img->contenu[pos] = c;
}

void    incrusterImage(ExiaImage* dest, ExiaImage* src,int posX, int posY)     // incruste src à la position (i,j) de la destination
{
    int i,j;
    for(i=0; i< src->resY; i++)
        for(j=0; j< src->resX; j++)
        {
            char c = lirePixel(src,i,j);
            ecrirePixel(dest, posY + i, posX + j, c);
        }
}

void    centrerImageDans(ExiaImage* dest,ExiaImage* src,int posX, int posY)   // incruste src à la position (i,j) de la destination
{                                                                       //
    incrusterImage(dest,src, posX - src->resX/2, posY - src->resY/2);
}


void    afficherImage(ExiaImage* img)
{
    system("cls"); // A REMPLACER par system("clear"); en Linux
    int i, j;
    for(i=0; i< img->resY; i++)
    {
        for(j=0; j< img->resX; j++)
        {
          char c =  lirePixel(img, i, j);
          printf("%c", c);
        }
        printf("\n");
    }
}
