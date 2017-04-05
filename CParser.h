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
 * Constructeur de param�tres 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
	CParser();

/*********************
 * Destructeur de param�tres 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
	~CParser();

/*********************
 * Parse le fichier 
 * *******************
 * Entr�e : Chaine de caract�re (nom du fichier)
 * Pr�condition : Rien 
 * Sortie : rien
 * Postcondition : L'objet faisant appel � cette fonction voit ses attributs uiNbLignes, uiNbColonnes et ppdPARMatrice chang�s en fonction de ce que le parser a trouv� dans le fichier.
**********************/
void PARLireFichier(char* pcPath);

/*********************
 * Met en majuscule la chaine 1 arg
 * *******************
 * Entr�e : chaine de caract�re
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : la chaine pass�e en param�tre est en majuscule
**********************/
	void PARupperString(char* pcString);

/*********************
 * Accesseur en lecture du nombre de colonnes 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : nombre de colonnes de la matrice
 * Postcondition : rien
**********************/
	unsigned int getUiPARNbColonnes();

/*********************
 * Accesseur en lecture du nombre de ligne 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : nombre de lignes de la matrice
 * Postcondition : rien
**********************/
	unsigned int getUiPARNbLignes();

/*********************
 * Accesseur en lecture de la matrice 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : matrice
 * Postcondition : rien
**********************/
	double** getPpdPARMatrice();

	
};
#endif C_PARSER_H
