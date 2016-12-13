#include <stdio.h>
#include <stdlib.h>
#include "memoireChangeTaille.h"
#include "additionnerStructure.h"


fichierPBM addition(fichierPBM fUN, fichierPBM fDEUX)
{
    int i = 0;
    int j = 0;
    fichierPBM fFinal;
    fFinal.largeur = fUN.largeur + fDEUX.largeur + 1;
    fFinal.hauteur = fUN.hauteur;
    fFinal = initialisationTableau(fFinal);
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
            fFinal.tblPBM[i][j] = fDEUX.tblPBM[i][j-fUN.largeur - 1];
        }
    }
    return fFinal;
}

int main(){

    fichierPBM fFinal;

    fichierPBM pBM;
    pBM.largeur = 3;
    pBM.hauteur = 5;
    pBM = initialisationTableau(pBM);

    pBM.tblPBM[0][0] = 'X';
    pBM.tblPBM[0][1] = ' ';
    pBM.tblPBM[0][2] = 'X';

    pBM.tblPBM[1][0] = 'X';
    pBM.tblPBM[1][1] = ' ';
    pBM.tblPBM[1][2] = 'X';

    pBM.tblPBM[2][0] = 'X';
    pBM.tblPBM[2][1] = 'X';
    pBM.tblPBM[2][2] = 'X';

    pBM.tblPBM[3][0] = ' ';
    pBM.tblPBM[3][1] = ' ';
    pBM.tblPBM[3][2] = 'X';

    pBM.tblPBM[4][0] = ' ';
    pBM.tblPBM[4][1] = ' ';
    pBM.tblPBM[4][2] = 'X';


    fichierPBM pBMd;
    pBMd.largeur = 3;
    pBMd.hauteur = 5;
    pBMd = initialisationTableau(pBMd);
    pBMd.tblPBM[0][0] = 'X';
    pBMd.tblPBM[0][1] = 'X';
    pBMd.tblPBM[0][2] = 'X';

    pBMd.tblPBM[1][0] = 'X';
    pBMd.tblPBM[1][1] = ' ';
    pBMd.tblPBM[1][2] = 'X';

    pBMd.tblPBM[2][0] = 'X';
    pBMd.tblPBM[2][1] = ' ';
    pBMd.tblPBM[2][2] = 'X';

    pBMd.tblPBM[3][0] = 'X';
    pBMd.tblPBM[3][1] = ' ';
    pBMd.tblPBM[3][2] = 'X';

    pBMd.tblPBM[4][0] = 'X';
    pBMd.tblPBM[4][1] = 'X';
    pBMd.tblPBM[4][2] = 'X';


    fichierPBM pBMde;
    pBMde.largeur = 3;
    pBMde.hauteur = 5;
    pBMde = initialisationTableau(pBMde);

    pBMde.tblPBM[0][0] = 'X';
    pBMde.tblPBM[0][1] = 'X';
    pBMde.tblPBM[0][2] = 'X';

    pBMde.tblPBM[1][0] = 'X';
    pBMde.tblPBM[1][1] = ' ';
    pBMde.tblPBM[1][2] = ' ';

    pBMde.tblPBM[2][0] = 'X';
    pBMde.tblPBM[2][1] = 'X';
    pBMde.tblPBM[2][2] = 'X';

    pBMde.tblPBM[3][0] = 'X';
    pBMde.tblPBM[3][1] = ' ';
    pBMde.tblPBM[3][2] = 'X';

    pBMde.tblPBM[4][0] = 'X';
    pBMde.tblPBM[4][1] = 'X';
    pBMde.tblPBM[4][2] = 'X';
 //-----------------------------------------------

    int x = 10;
    int y = 19;
    pBM = changeTaillePBM(pBM, x, y);
    pBMd = changeTaillePBM(pBMd, x, y);
    pBMde = changeTaillePBM(pBMde, x, y);
    fFinal = addition(pBM, pBMd);
    fFinal = addition(fFinal, pBMde);

    testTableau(fFinal);
    //changeTaillePBM(pBM, 15, 29);
    libereTableau(fFinal);
    libereTableau(pBMd);
    libereTableau(pBMde);
    return 0;
}
