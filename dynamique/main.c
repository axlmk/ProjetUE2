#include <stdio.h>
#include <stdlib.h>
#include "memoireChangeTaille.h"
#include "additionnerStructure.h"
#include <windows.h>
#include <time.h>

struct tm heure (){
        time_t secondes;    /*time_t est un type de variable qui indique un nombre de secondes*/
        struct tm instant;  /*Une structure tm contient des variables concernant la date et l'heure*/

        time(&secondes);
        instant = *localtime(&secondes);
        return instant;
    }

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
    char test[6] = {'a', '.', 'p', 'b', 'm', '\0'};
    if (nFichier == 10)
    {

    }
    else
    {
        test[0] = nFichier + '0';
    }
	FILE *fichierImagePBM = fopen(test,"r");
	fichierPBM fPBM;

    int caractereLu;
	int tabl[2];
	char copie[50];
    const char s[2] = " ";
    char *token;
    const char o[2] = "\n\r";

// Passe les 3 premières lignes
    do{
        fgets(copie, 20, fichierImagePBM);
        i++;
    }while(i < 3);

    token = strtok(fgets(copie, 20, fichierImagePBM), s);

    i = 0;
// Recupere les valeurs en longueur et en largeur de l'image
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
            caractereLu = getc(fichierImagePBM);

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
    //testTableau(fPBM);


	fclose(fichierImagePBM);

	return fPBM;
}

int main(){

    int x = 5, y = 9;

    fichierPBM fHeu1;
    fichierPBM fHeu2;
    fichierPBM fMin1;
    fichierPBM fMin2;
    fichierPBM fSec1;
    fichierPBM fSec2;
    fichierPBM fPoint;

    struct tm horaire;
    horaire = heure();
    int a, b, i = 0;

    for (a = 0; a <= horaire.tm_hour ; a+=10)
    {
        i++;
    }

    fHeu1 = creeStructure(i - 1);
    fHeu1 = changerStructure(fHeu1);
    fHeu1 = changeTaillePBM(fHeu1, x, y);
    fHeu2 = creeStructure(horaire.tm_hour - (i - 1)*10);
    fHeu2 = changerStructure(fHeu2);
    fHeu2 = changeTaillePBM(fHeu2, x, y);
    fHeu1 = addition(fHeu1, fHeu2);

    fPoint = creeStructure(10);
    fPoint = changerStructure(fPoint);
    fPoint = changeTaillePBM(fPoint, x, y);
    fHeu1 = addition (fHeu1, fPoint);

    i = 0;
    for (a = 0; a <= horaire.tm_min ; a+=10)
    {
        i++;
    }
    fMin1 = creeStructure(i - 1);
    fMin1 = changerStructure(fMin1);
    fMin1 = changeTaillePBM(fMin1, x, y);
    fMin2 = creeStructure(horaire.tm_min - (i-1)*10);
    fMin2 = changerStructure(fMin2);
    fMin2 = changeTaillePBM(fMin2, x, y);
    fMin1 = addition(fMin1, fMin2);
    fMin1 = addition(fHeu1, fMin1);

    fPoint = creeStructure(10);
    fPoint = changerStructure(fPoint);
    fPoint = changeTaillePBM(fPoint, x, y);
    fMin1 = addition (fMin1, fPoint);

    i = 0;
    for (a = 0; a <= horaire.tm_sec ; a+=10)
    {
        i++;
    }
    fSec1 = creeStructure(i - 1);
    fSec1 = changerStructure(fSec1);
    fSec1 = changeTaillePBM(fSec1, x, y);
    fSec2 = creeStructure(horaire.tm_sec - (i-1)*10);
    fSec2 = changerStructure(fSec2);
    fSec2 = changeTaillePBM(fSec2, x, y);
    fSec1 = addition(fSec1, fSec2);
    fSec1 = addition(fMin1, fSec1);

    int larg = ((80 - fSec1.largeur) / 2);
    int haut = ((24 - fSec1.hauteur) / 2);

    testTableau(fSec1, haut, larg);

    return 0;
}
