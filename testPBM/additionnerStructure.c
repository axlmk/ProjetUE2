#include <stdlib.h>
#include <stdio.h>
#include "additionnerStructure.h"
#include "memoireChangeTaille.h"

fichierPBM addition(fichierPBM fUN, fichierPBM fDEUX)
{
    d
    int i = 0;
    int j = 0;
    fichierPBM fFinal;
    fFinal.largeur = fUN.largeur + fDEUX.largeur;
    fFinal.hauteur = fUN.hauteur + fDEUX.hauteur;
    fFinal.tblPBM = initialisationTableau(fFinal);
    for(; i < largeur; i++)
    {
        j = 0;
        for(; j < hauteur; j++)
        {
            fFinal.tblPBM[i][j] = fUN;
        }
        for(; j < hauteur; j++)
        {
            fFinal.tblPBM[i][j] = fDEUX;
        }
    }

    libereTableau(fFinal);
}
