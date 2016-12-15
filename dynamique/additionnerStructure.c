#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "additionnerStructure.h"
#include "memoireChangeTaille.h"


fichierPBM addition(fichierPBM fUN, fichierPBM fDEUX)
{

    int i = 0;
    int j = 0;
    fichierPBM fFinal;
    fFinal.largeur = fUN.largeur + fDEUX.largeur + 1;
    fFinal.hauteur = fUN.hauteur;
    fFinal= initialisationTableau(fFinal);

    for(; i < fFinal.hauteur; i++)
    {
        j = 0;
        for(; j < fUN.largeur; j++)
        {
            fFinal.tblPBM[i][j] = fUN.tblPBM[i][j];
        }
        fFinal.tblPBM[i][j] = ' ';
        j++;
        for(; j < fFinal.largeur; j++)
        {
            fFinal.tblPBM[i][j] = fDEUX.tblPBM[i][j-fUN.largeur-1];
        }

    }
    return fFinal;
}
