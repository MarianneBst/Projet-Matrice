#ifndef PROJETMATRICE_CMATRICE_H
#define PROJETMATRICE_CMATRICE_H

#include <stdio.h>
#include <iostream>
class CParser;

template <class TypeMatrice>
class CMatrice
{
	private:
		TypeMatrice** pptpmMATMatrice;
		unsigned int uiMATNbLignes;
		unsigned int uiMATNbColonnes;


	public:
		/* *********constructeurs * *********/
/*********************
 * Constructeur par défaut 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice>();
/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entrée : objet de la classe CMatrice
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice>(CMatrice<TypeMatrice> &MATobjet);
/*********************
 * Constructeur de paramètres 2 args
 * *******************
 * Entrée : le nombre de lignes et de colonnes
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice>(unsigned int uiNbLignes, unsigned int uiNbColonnes);

/*********************
 * Constructeur de paramètres 1 arg
 * *******************
 * Entrée : objet CParser
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice>(CParser &PARObjet);

		/* *********** Destructeur * *********/
/*********************
 * Destructeur 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		~CMatrice();

		/* ******** Getter ******* **/
/*********************
 * Accesseur en lecture du nombre de lignes 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : nombre de lignes de la matrice
 * Postcondition : rien
**********************/
		unsigned int MATLireNbLignes();
/*********************
 * Accesseur en lecture du nombre de colonnes 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : nombre de colonnes de la matrice
 * Postcondition : rien
**********************/
		unsigned int MATLireNbColonnes();
/*********************
 * Accesseur en lecture de la matrice 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : la matrice
 * Postcondition : rien
**********************/
		void MATAfficherMatrice();
/*********************
 * Accesseur en lecture d'un élément de la matrice 2 arg
 * *******************
 * Entrée : le numéro de la ligne et de la colonne
 * Précondition : Les numéros de lignes commencent à 1 et ne doivent pas dépasser la taille de la matrice
 * Sortie : l'élément
 * Postcondition : rien
**********************/
		TypeMatrice MATLireElement(unsigned int uinumLigne, unsigned int uinumColonne);

		/* **********Setter * **************/
/*********************
 * Accesseur en écriture d'un élément de la matrice 3 arg
 * *******************
 * Entrée : le nouvel élément le numéro de la ligne et de la colonne
 * Précondition : Les numéros de lignes commencent à 1 et ne doivent pas dépasser la taille de la matrice
 * Sortie : nombre de colonnes de la matrice
 * Postcondition : rien
**********************/
		void MATModifierElement(TypeMatrice tpmElement, unsigned int uinumLigne, unsigned int uinumColonne);

		/* ******* Opérations* *******/
/*********************
 * Transposée d'une matrice 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : la matrice transposée
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice> MATTransposee();

};
/*********************
 * Surcharge de l'opérateur * 2 arg
 * *******************
 * Entrée : une matrice et un coefficient
 * Précondition : le coefficient doit être de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATobjet, TypeMatrice tpmCoeff);

/*********************
 * Surcharge de l'opérateur / 2 arg
 * *******************
 * Entrée : une matrice et un coefficient
 * Précondition : le coefficient doit être de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(CMatrice<TypeMatrice> MATobjet, TypeMatrice tpmCoeff);

/*********************
 * Surcharge de l'opérateur * 2 arg
 * *******************
 * Entrée : une matrice et un coefficient
 * Précondition : le coefficient doit être de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(TypeMatrice tpmCoeff, CMatrice<TypeMatrice> MATobjet);

/*********************
 * Surcharge de l'opérateur / 2 arg
 * *******************
 * Entrée : une matrice et un coefficient
 * Précondition : le coefficient doit être de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(TypeMatrice tpmCoeff, CMatrice<TypeMatrice> MATobjet);

/*********************
 * Surcharge de l'opérateur + 2 arg
 * *******************
 * Entrée : deux matrices
 * Précondition : il faut que les matrices soient de même dimensions
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator+(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

/*********************
 * Surcharge de l'opérateur - 2 arg
 * *******************
 * Entrée : deux matrices
 * Précondition : il faut que les matrices soient de même dimensions
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator-(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

/*********************
 * Surcharge de l'opérateur * 2 arg
 * *******************
 * Entrée : deux matrices
 * Précondition : il faut que le nombre de colonnes de la matrice A soit égal au nombre de lignes de la matrice B
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <typename TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

#include"CMatrice.cpp"
#include "COperation.cpp"

#endif

