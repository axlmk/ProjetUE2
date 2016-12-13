#ifndef MEMOIRECHANGETAILLE_H_INCLUDED
#define MEMOIRECHANGETAILLE_H_INCLUDED
#include "structureFichierPBM.h"

fichierPBM initialisationTableau(fichierPBM pBM);
void libereTableau(fichierPBM pBM);
void testTableau(fichierPBM pBM);
fichierPBM changeTaillePBM(fichierPBM oldPBM, int largeurX, int hauteurY);

#endif // MEMOIRECHANGETAILLE_H_INCLUDED

