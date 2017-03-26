#ifndef PROJETMATRICE_CMATRICE_H
#define PROJETMATRICE_CMATRICE_H

#include <stdio.h>
#include <iostream>


template <class TypeMatrice>
class CMatrice
{
	private:
		TypeMatrice** pptpmMATMatrice;
		unsigned int uiMATNbLignes;
		unsigned int uiMATNbColonnes;


	public:
		//constructeur
		CMatrice<TypeMatrice>();
		CMatrice<TypeMatrice>(CMatrice<TypeMatrice>* &objet);
		CMatrice<TypeMatrice>(unsigned int uiNbLignes, unsigned int uiNbColonnes);
		//Getter
		int MATLireNbLignes();
		int MATLireNbColonnes();
		void MATAfficherMatrice();
		//Setter
		void MATModifierElement(TypeMatrice tpmElement, unsigned int uinumLigne, unsigned int uinumColonne);
		//opérations
		CMatrice<TypeMatrice> operator*(float fCoeff);
		CMatrice<TypeMatrice> operator/(float fCoeff);

		CMatrice<TypeMatrice> operator+(CMatrice<TypeMatrice> MATParam);
	    CMatrice<TypeMatrice> operator-(CMatrice<TypeMatrice> MATParam);
		CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATParam);

		CMatrice<TypeMatrice> MATTransposee();

};

#include"CMatrice.cpp"

#endif PROJETMATRICE_CMATRICE_H

