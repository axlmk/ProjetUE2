#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED
#include <time.h>

typedef struct tm TimeInfo;

#define TAILLE_MAX_FICHIER 200

typedef struct SSession
{
    char        nomFichierImage[TAILLE_MAX_FICHIER];
    int         typeLancement;
    int         largeur;
    int         hauteur;
    int         positionX;
    int         positionY;
    TimeInfo*   infoDate;
} Session;

void majDateSession(Session* s);
void enregistrer(Session* s, char *nomFichierHisto);

#endif // HISTORIQUE_H_INCLUDED
