#ifndef TRAITEMENTSTRUCTURE_H_INCLUDED
#define TRAITEMENTSTRUCTURE_H_INCLUDED
typedef struct fichierPBM fichierPBM;
struct fichierPBM
{
    int hauteur;
    int largeur;
    char **tblPBM;
};

fichierPBM initialisationTableau(fichierPBM pBM);
fichierPBM changeTaillePBM(fichierPBM oldPBM, int largeurX, int hauteurY);
void libereTableau(fichierPBM pBM);
void afficheTableau(fichierPBM pBM, int haut, int larg);


#endif // TRAITEMENTSTRUCTURE_H_INCLUDED
