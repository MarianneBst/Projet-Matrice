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
		CMatrice<TypeMatrice>(CMatrice<TypeMatrice> &objet);
		CMatrice<TypeMatrice>(unsigned int uiNbLignes, unsigned int uiNbColonnes);
		//Destructeur
		~CMatrice();
		//Getter
		unsigned int MATLireNbLignes();
		unsigned int MATLireNbColonnes();
		void MATAfficherMatrice();
		TypeMatrice MATLireElement(unsigned int uinumLigne, unsigned int uinumColonne);
		//Setter
		void MATModifierElement(TypeMatrice tpmElement, unsigned int uinumLigne, unsigned int uinumColonne);
		//opérations
		CMatrice<TypeMatrice> operator=(CMatrice<TypeMatrice>* MATParam);
		CMatrice<TypeMatrice> MATTransposee();

};
template <typename TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATobjet, TypeMatrice fCoeff);

template <typename TypeMatrice>
CMatrice<TypeMatrice> operator/(CMatrice<TypeMatrice> MATobjet, TypeMatrice fCoeff);

template <typename TypeMatrice>
CMatrice<TypeMatrice> operator+(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

template <typename TypeMatrice>
CMatrice<TypeMatrice> operator-(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);
//
//template <typename TypeMatrice>
//CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

#include"CMatrice.cpp"

#endif PROJETMATRICE_CMATRICE_H

