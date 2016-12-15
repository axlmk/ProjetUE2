#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header/traitementPBM.h"
#include "header/traitementStructure.h"

fichierPBM changerStructure(fichierPBM fPBM)
{
    int i = 0, j = 0;
    for(; i < fPBM.hauteur; i++)
    {
        for( j = 0; j < fPBM.largeur; j++)
        {
            if(fPBM.tblPBM[i][j] == '0')
            {
                fPBM.tblPBM[i][j] = ' ';
            }
            else
            {
                fPBM.tblPBM[i][j] = 'X';
            }
        }
    }

    return fPBM;
}


fichierPBM creeStructure(int nFichier)
{
    int i = 0, j = 0;
    char test[10] = {'a', '.', 'p', 'b', 'm', '\0'};
    if (nFichier == 10)
    {

    }
    else
    {
        test[0] = nFichier  + '0';
    }
	FILE *fichierImagePBM = fopen(test,"r");
	fichierPBM fPBM;

    int caractereLu;
	int tabl[2];
	char k[2];
	char copie[50];
    char s[2] = " ";
    char *token;
    const char o[2] = "\n";

    do{
        fgets(copie, 20, fichierImagePBM);
        i++;
    }while(i < 3);

    token = strtok(fgets(copie, 20, fichierImagePBM), s);

    i = 0;

    while( token != NULL )
    {
        tabl[i] = atoi(token);
        token = strtok(NULL, s);
        i++;
    }
    fPBM.largeur = tabl[0];
    fPBM.hauteur = tabl[1];

    fPBM = initialisationTableau(fPBM);
    for (i = 0; i < 5; i ++)
    {
        for (j = 0; j < 3; j++)
        {

            caractereLu = fgetc(fichierImagePBM);

            if (caractereLu != 1 && caractereLu != 0)
            {
                fPBM.tblPBM[i][j] = caractereLu;
                caractereLu = getc(fichierImagePBM);
            }
            else
            {

            }
        }
    }

	fclose(fichierImagePBM);

	return fPBM;
}
