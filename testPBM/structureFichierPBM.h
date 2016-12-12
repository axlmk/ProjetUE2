#ifndef STRUCTUREFICHIERPBM_H_INCLUDED
#define STRUCTUREFICHIERPBM_H_INCLUDED

typedef struct fichierPBM fichierPBM; // creation de la structure qui va nous permettre de stocker les informations du fichier PBM

struct fichierPBM
{
    int hauteur;
    int largeur;
    char **tblPBM; //tableau deux dimensions contenant les informations de couleur du fichier en fonction de sa position
};

#endif // STRUCTUREFICHIERPBM_H_INCLUDED
