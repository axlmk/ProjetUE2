#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "historique.h"

void majDateSession(Session* s)
{
    time_t rawtime;
    time(&rawtime);
    s->infoDate = localtime(&rawtime);
}

void ImprimerDate(FILE* g, TimeInfo* info)
{
   fprintf(g,"%d/%d/%d %d:%d:%d", info->tm_mday, info->tm_mon + 1 , info->tm_year + 1900, info->tm_hour, info->tm_min, info->tm_sec);
}

void enregistrer(Session* s, char *nomFichierHisto)
{
    FILE* g;
    g = fopen(nomFichierHisto, "a");

    ImprimerDate(g, s->infoDate);
    if (g != NULL)
    {
        if(s->typeLancement == 1)
        {
            fprintf(g,";%d;%s\n", s->typeLancement, s->nomFichierImage);
        }
        else if (s->typeLancement == 2)
        {
            fprintf(g,";%d;%dx%d\n", s->typeLancement, s->hauteur, s->largeur);
        }
        else if (s->typeLancement == 3)
        {
            fprintf(g,";%d;%dx%d\n", s->typeLancement, s->positionX, s->positionY);
        }
        fclose(g);
    }
    else
        printf("Le fichier %s n'existe pas ou n'a pas pu être ouvert",nomFichierHisto);
}
