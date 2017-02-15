#ifndef EXIAIMAGE_H_INCLUDED
#define EXIAIMAGE_H_INCLUDED

typedef struct ExiaImg
{
    int type;
    int resX;       // largeur de l'image en nombre de pixel
    int resY;       // hauteur de l'image en nombre de pixel
    char *contenu;  // tableau alloué dynamiquement representant l'image à raison de 1 car par pixel
} ExiaImage;

void    allouerImage(ExiaImage* img);                                   // alloue le contenu en foction de la taille (resX,resY)
void    libererImage(ExiaImage* img);                                   // libere le contenu
void    initialiserContenu(ExiaImage* img, char c);                     // remplit le contenu avec le caracter c
void    lireFichier(ExiaImage* img, char* nomFichierPBM);               // lire le fichier dansla structure ExiaImage
char    lirePixel(ExiaImage* img, int i, int j);                        // retourne le pixel de coordonnees (i,j)
void    ecrirePixel(ExiaImage* img, int i, int j, char c);              // écrit c dans le pixel (i,j)
void    incrusterImage(ExiaImage* dest,ExiaImage* src,int i, int j);    // incruste src à la position (i,j) de la destination
                                                                        // ce qui veur dire que l'origine de src se trouvera à i,j
void    centrerImageDans(ExiaImage* dest,ExiaImage* src,int i, int j);  // incruste src à la position (i,j) de la destination
                                                                        // ce qui veur dire que le centre de src se trouvera à i,j
void    afficherImage(ExiaImage* img);

#endif // EXIAIMAGE_H_INCLUDED
