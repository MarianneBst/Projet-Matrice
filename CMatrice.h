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
 * Constructeur par d�faut 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice>();
/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entr�e : objet de la classe CMatrice
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice>(CMatrice<TypeMatrice> &MATobjet);
/*********************
 * Constructeur de param�tres 2 args
 * *******************
 * Entr�e : le nombre de lignes et de colonnes
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice>(unsigned int uiNbLignes, unsigned int uiNbColonnes);

/*********************
 * Constructeur de param�tres 1 arg
 * *******************
 * Entr�e : objet CParser
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice>(CParser &PARObjet);

		/* *********** Destructeur * *********/
/*********************
 * Destructeur 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		~CMatrice();

		/* ******** Getter ******* **/
/*********************
 * Accesseur en lecture du nombre de lignes 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : nombre de lignes de la matrice
 * Postcondition : rien
**********************/
		unsigned int MATLireNbLignes();
/*********************
 * Accesseur en lecture du nombre de colonnes 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : nombre de colonnes de la matrice
 * Postcondition : rien
**********************/
		unsigned int MATLireNbColonnes();
/*********************
 * Accesseur en lecture de la matrice 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : la matrice
 * Postcondition : rien
**********************/
		void MATAfficherMatrice();
/*********************
 * Accesseur en lecture d'un �l�ment de la matrice 2 arg
 * *******************
 * Entr�e : le num�ro de la ligne et de la colonne
 * Pr�condition : Les num�ros de lignes commencent � 1 et ne doivent pas d�passer la taille de la matrice
 * Sortie : l'�l�ment
 * Postcondition : rien
**********************/
		TypeMatrice MATLireElement(unsigned int uinumLigne, unsigned int uinumColonne);

		/* **********Setter * **************/
/*********************
 * Accesseur en �criture d'un �l�ment de la matrice 3 arg
 * *******************
 * Entr�e : le nouvel �l�ment le num�ro de la ligne et de la colonne
 * Pr�condition : Les num�ros de lignes commencent � 1 et ne doivent pas d�passer la taille de la matrice
 * Sortie : nombre de colonnes de la matrice
 * Postcondition : rien
**********************/
		void MATModifierElement(TypeMatrice tpmElement, unsigned int uinumLigne, unsigned int uinumColonne);

		/* ******* Op�rations* *******/
/*********************
 * Transpos�e d'une matrice 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : la matrice transpos�e
 * Postcondition : rien
**********************/
		CMatrice<TypeMatrice> MATTransposee();

};
/*********************
 * Surcharge de l'op�rateur * 2 arg
 * *******************
 * Entr�e : une matrice et un coefficient
 * Pr�condition : le coefficient doit �tre de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATobjet, TypeMatrice tpmCoeff);

/*********************
 * Surcharge de l'op�rateur / 2 arg
 * *******************
 * Entr�e : une matrice et un coefficient
 * Pr�condition : le coefficient doit �tre de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(CMatrice<TypeMatrice> MATobjet, TypeMatrice tpmCoeff);

/*********************
 * Surcharge de l'op�rateur * 2 arg
 * *******************
 * Entr�e : une matrice et un coefficient
 * Pr�condition : le coefficient doit �tre de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(TypeMatrice tpmCoeff, CMatrice<TypeMatrice> MATobjet);

/*********************
 * Surcharge de l'op�rateur / 2 arg
 * *******************
 * Entr�e : une matrice et un coefficient
 * Pr�condition : le coefficient doit �tre de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(TypeMatrice tpmCoeff, CMatrice<TypeMatrice> MATobjet);

/*********************
 * Surcharge de l'op�rateur + 2 arg
 * *******************
 * Entr�e : deux matrices
 * Pr�condition : il faut que les matrices soient de m�me dimensions
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator+(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

/*********************
 * Surcharge de l'op�rateur - 2 arg
 * *******************
 * Entr�e : deux matrices
 * Pr�condition : il faut que les matrices soient de m�me dimensions
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator-(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

/*********************
 * Surcharge de l'op�rateur * 2 arg
 * *******************
 * Entr�e : deux matrices
 * Pr�condition : il faut que le nombre de colonnes de la matrice A soit �gal au nombre de lignes de la matrice B
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <typename TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

#include"CMatrice.cpp"
#include "COperation.cpp"

#endif

