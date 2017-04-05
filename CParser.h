#ifndef C_PARSER_H
#define C_PARSER_H
#include "CMatrice.h"
#include <iostream>

class CParser
{
private:
	unsigned int uiPARNbColonnes;
	unsigned int uiPARNbLignes;
	double** ppdPARMatrice;
public:
/*********************
 * Constructeur de paramètres 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
	CParser();

/*********************
 * Destructeur de paramètres 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
	~CParser();

/*********************
 * Parse le fichier 
 * *******************
 * Entrée : Chaine de caractère (nom du fichier)
 * Précondition : Rien 
 * Sortie : rien
 * Postcondition : L'objet faisant appel à cette fonction voit ses attributs uiNbLignes, uiNbColonnes et ppdPARMatrice changés en fonction de ce que le parser a trouvé dans le fichier.
**********************/
void PARLireFichier(char* pcPath);

/*********************
 * Met en majuscule la chaine 1 arg
 * *******************
 * Entrée : chaine de caractère
 * Précondition : rien
 * Sortie : rien
 * Postcondition : la chaine passée en paramètre est en majuscule
**********************/
	void PARupperString(char* pcString);

/*********************
 * Accesseur en lecture du nombre de colonnes 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : nombre de colonnes de la matrice
 * Postcondition : rien
**********************/
	unsigned int getUiPARNbColonnes();

/*********************
 * Accesseur en lecture du nombre de ligne 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : nombre de lignes de la matrice
 * Postcondition : rien
**********************/
	unsigned int getUiPARNbLignes();

/*********************
 * Accesseur en lecture de la matrice 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : matrice
 * Postcondition : rien
**********************/
	double** getPpdPARMatrice();

	
};
#endif C_PARSER_H
