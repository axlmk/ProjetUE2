#include <stdio.h>
#include <stdlib.h>
#include "memoireChangeTaille.h"
#include "additionnerStructure.h"


fichierPBM addition(fichierPBM fUN, fichierPBM fDEUX)
{
    int i = 0;
    int j = 0;
    fichierPBM fFinal;
    fFinal.largeur = fUN.largeur + fDEUX.largeur;
    fFinal.hauteur = fUN.hauteur + fDEUX.hauteur;
    printf("%d\n\n", fFinal.hauteur);

    fFinal = initialisationTableau(fFinal);
    for(; i < fFinal.largeur; i++)
    {
        j = 0;
        for(; j < fUN.hauteur; j++)
        {
            //printf("test1");
            fFinal.tblPBM[i][j] = fUN.tblPBM[i][j];
        }
        for(; j < fFinal.hauteur; j++)
        {
            printf("j%d", j);
            fFinal.tblPBM[i][j] = fDEUX.tblPBM[i][j];
        }
        printf("test4\n\n");
    }
    printf("test5");
    libereTableau(fFinal);
}

int main(){

    fichierPBM fFinal;

//------------------------------------------------
    fichierPBM pBM;
    pBM.largeur = 3;
    pBM.hauteur = 5;
    pBM = initialisationTableau(pBM);

    pBM.tblPBM[0][0] = 'X';
    pBM.tblPBM[0][1] = ' ';
    pBM.tblPBM[0][2] = ' ';

    pBM.tblPBM[1][0] = 'X';
    pBM.tblPBM[1][1] = ' ';
    pBM.tblPBM[1][2] = ' ';

    pBM.tblPBM[2][0] = 'X';
    pBM.tblPBM[2][1] = 'X';
    pBM.tblPBM[2][2] = 'X';

    pBM.tblPBM[3][0] = 'X';
    pBM.tblPBM[3][1] = ' ';
    pBM.tblPBM[3][2] = 'X';

    pBM.tblPBM[4][0] = 'X';
    pBM.tblPBM[4][1] = 'X';
    pBM.tblPBM[4][2] = 'X';

    int i = 0;
    for (i = 0; i < pBM.hauteur; i++)
    {
        int j = 0;
        for (; j < pBM.largeur; j++)
        {
                printf("%c",pBM.tblPBM[i][j]);
        }
        printf("\n");
    }

    printf("-----\n");
 //-----------------------------------------------



//------------------------------------------------
    fichierPBM pBMd;
    pBMd.largeur = 3;
    pBMd.hauteur = 5;
    pBMd = initialisationTableau(pBMd);

    pBMd.tblPBM[0][0] = 'X';
    pBMd.tblPBM[0][1] = ' ';
    pBMd.tblPBM[0][2] = ' ';

    pBMd.tblPBM[1][0] = 'X';
    pBMd.tblPBM[1][1] = ' ';
    pBMd.tblPBM[1][2] = ' ';

    pBMd.tblPBM[2][0] = 'X';
    pBMd.tblPBM[2][1] = 'X';
    pBMd.tblPBM[2][2] = 'X';

    pBMd.tblPBM[3][0] = 'X';
    pBMd.tblPBM[3][1] = ' ';
    pBMd.tblPBM[3][2] = 'X';

    pBMd.tblPBM[4][0] = 'X';
    pBMd.tblPBM[4][1] = 'X';
    pBMd.tblPBM[4][2] = 'X';

    for (i = 0; i < pBMd.hauteur; i++)
    {
        int j = 0;
        for (; j < pBMd.largeur; j++)
        {
                printf("%c", pBMd.tblPBM[i][j]);
        }
        printf("\n");
    }

    printf("-----\n");
 //-----------------------------------------------



    fFinal = addition(pBM, pBMd);
    testTableau(fFinal);

    libereTableau(pBM);
    libereTableau(pBMd);
    libereTableau(fFinal);
    return 0;
}
