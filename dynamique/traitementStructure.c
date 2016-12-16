#include <stdlib.h>
#include <stdio.h>
#include "header/traitementStructure.h"

fichierPBM initialisationTableau(fichierPBM pBM)
{
    int i = 0;
    pBM.tblPBM = malloc((pBM.hauteur) * sizeof(char*));
    for(; i < pBM.hauteur ; i++){
        pBM.tblPBM[i] = malloc(pBM.largeur * sizeof(char));
    }
    if (pBM.tblPBM == NULL)
    {
        printf("Erreur lors de l'allocation memoire dynamique.");
        exit(0);
    }
    for (i = 0; i < pBM.hauteur; i++)
    {
        int j = 0;
        for (; j < pBM.largeur; j++)
        {
                pBM.tblPBM[i][j] = ' ';
        }
    }
    return pBM;
}

fichierPBM changeTaillePBM(fichierPBM oldPBM, int largeurX, int hauteurY)
{

    fichierPBM newPBM;
    newPBM.largeur = largeurX;
    newPBM.hauteur = hauteurY;

    newPBM = initialisationTableau(newPBM);

    if(oldPBM.tblPBM[1][1] == 'X')
    {
        int i = 0;
        int j = 0;
        for(; i < largeurX / 2; i ++)
        {

        }
        for(; j < hauteurY / 3 - 1;  j++)
        {

        }
        newPBM.tblPBM[j][i] = 'X';

        for(j = 0; j < ((hauteurY * 2) / 3);  j++)
        {

        }
        newPBM.tblPBM[j][i] = 'X';
    }



    if(oldPBM.tblPBM[0][1] == 'X') //regarde si un point clé de l'image est noir ou blanc
    {
        int i = 0;
        for(; i <= newPBM.largeur; i ++){
            newPBM.tblPBM[0][i] = 'X'; //remplis la ligne correspondant à un segment de caractère
        }
    }
    else{
        int i = 0;
        for(; i < largeurX; i ++){
            if(newPBM.tblPBM[0][i] == 'X') //puisque que le tableau a ete initalise a 0, il faut verifier que l'on ecrit pas par dessus un 1
            {

            }
            else
            {
                newPBM.tblPBM[0][i] = ' ';

            }
        }
    }

    if(oldPBM.tblPBM[1][0] == 'X')
    {
        int i = 0;
        for(; i < hauteurY / 2 + 1; i ++){
            newPBM.tblPBM[i][0] = 'X';
        }
    }
    else{
        int i = 0;
        for(; i < hauteurY / 2 + 1; i ++){
            if(newPBM.tblPBM[i][0] == 'X')
            {

            }
            else
            {
                newPBM.tblPBM[i][0] = ' ';
            }
        }
    }

    if(oldPBM.tblPBM[1][2] == 'X')
    {
        int i = 0;
        for(; i < hauteurY / 2 + 1; i ++){
            newPBM.tblPBM[i][newPBM.largeur-1] = 'X';
        }
    }
    else{
        int i = 0;
        for(; i < hauteurY / 2; i ++){
            if(newPBM.tblPBM[i][newPBM.largeur-1] == 'X')
            {

            }
            else
            {
                newPBM.tblPBM[i][newPBM.largeur-1] = ' ';
            }
        }
    }

    if(oldPBM.tblPBM[2][1] == 'X')
    {
        int i = 0;
        for(; i < largeurX; i ++){
            newPBM.tblPBM[newPBM.hauteur / 2][i] = 'X';
        }
    }
    else{
        int i = 0;
        for(; i < largeurX; i ++){
            if(newPBM.tblPBM[newPBM.hauteur / 2][i] == 'X')
            {

            }
            else
            {
                newPBM.tblPBM[newPBM.hauteur / 2][i] = ' ';
            }
        }
    }

    if(oldPBM.tblPBM[3][0] == 'X')
    {
        int i = 0;
        for(; i < hauteurY / 2+1; i ++){
            newPBM.tblPBM[i + newPBM.hauteur / 2][0] = 'X';
        }
    }
    else{
        int i = 0;
        for(; i < hauteurY / 2; i ++){
            if(newPBM.tblPBM[i + newPBM.hauteur/2][0] == 'X')
            {

            }
            else
            {
                newPBM.tblPBM[i + newPBM.hauteur/2+1][0] = ' ';
            }
        }
    }

    if(oldPBM.tblPBM[3][2] == 'X')
    {
        int i = 0;
        for(; i < hauteurY / 2; i ++){
            newPBM.tblPBM[i + newPBM.hauteur / 2+1][newPBM.largeur-1] = 'X';
        }
    }
    else{
        int i = 0;
        for(; i < hauteurY / 2; i ++){
            if(newPBM.tblPBM[i + newPBM.hauteur / 2][newPBM.largeur-1] == 'X')
            {

            }
            else
            {
                newPBM.tblPBM[i + newPBM.hauteur / 2+1][newPBM.largeur-1] = ' ';
            }
        }
    }

    if(oldPBM.tblPBM[4][1] == 'X')
    {
        int i = 0;
        for(; i < largeurX; i ++){
            newPBM.tblPBM[newPBM.hauteur-1][i] = 'X';
        }
    }
    else{
        int i = 0;
        for(; i < largeurX; i ++){
            if(newPBM.tblPBM[newPBM.hauteur-1][i] == 'X')
            {

            }
            else
            {
                newPBM.tblPBM[newPBM.hauteur-1][i] = ' ';
            }
        }
    }

    return newPBM;
}

void afficheTableau(fichierPBM pBM, int haut, int larg)
{
    int i;
    for (i = 0; i < haut; i++)
    {
        printf("\n");
    }
    int j = 0;
    int y = 0;
    for(; j < pBM.hauteur; j++)
    {
        for (y = 0; y < larg; y++)
        {
            printf(" ");
        }
        int z = 0;
        for(; z < pBM.largeur; z++)
        {
            printf(" %c", pBM.tblPBM[j][z]);
        }
        printf("\n");
    }
}

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
