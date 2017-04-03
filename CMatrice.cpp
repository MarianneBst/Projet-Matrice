#include "CMatrice.h"


/* **********constructeurs **********/
//par défaut
template <class TypeMatrice>
CMatrice<TypeMatrice>::CMatrice()
{
	uiMATNbColonnes = 1;
	uiMATNbLignes = 1;
	pptpmMATMatrice = new TypeMatrice* [uiMATNbLignes];
	pptpmMATMatrice[0] = new TypeMatrice[uiMATNbColonnes];
	pptpmMATMatrice[0][0] = 0;
}

//de paramètres
template <class TypeMatrice>
CMatrice<TypeMatrice>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes){
	unsigned int uiLigne;
	unsigned int uiColonne;
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;
	pptpmMATMatrice = new TypeMatrice* [uiNbLignes];
	for(uiLigne = 0; uiLigne < uiNbLignes; uiLigne++){
		pptpmMATMatrice[uiLigne] = new TypeMatrice[uiNbColonnes];
		for(uiColonne = 0; uiColonne < uiNbColonnes; uiColonne++){
			pptpmMATMatrice[uiLigne][uiColonne] = 0;
		}
	}
}

//de recopie
template <class TypeMatrice>
CMatrice<TypeMatrice>::CMatrice(CMatrice<TypeMatrice> &objet){
	unsigned int uiLigne;
	unsigned int uiColonne;

	uiMATNbColonnes = objet.uiMATNbColonnes;
	uiMATNbLignes = objet.uiMATNbLignes;
	
	pptpmMATMatrice = new TypeMatrice* [objet.uiMATNbLignes];
	for(uiLigne = 0; uiLigne < objet.uiMATNbLignes; uiLigne++){
		pptpmMATMatrice[uiLigne] = new TypeMatrice[objet.uiMATNbColonnes];
		for(uiColonne = 0; uiColonne < objet.uiMATNbColonnes; uiColonne++){
			pptpmMATMatrice[uiLigne][uiColonne] = objet.pptpmMATMatrice[uiLigne][uiColonne];
		}
	}
	
}

/* ************** Destructeurs **********/
template <class TypeMatrice>
CMatrice<TypeMatrice>::~CMatrice(){
	unsigned int uiLigne;

	for(uiLigne = 0; uiLigne < uiMATNbLignes; uiLigne++){
		delete(pptpmMATMatrice[uiLigne]);
	}
	delete(pptpmMATMatrice);
}


/* ************Getter *************/
template <typename TypeMatrice>
void CMatrice<TypeMatrice>::MATAfficherMatrice()
{
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	
	for(uiCptLignes = 0; uiCptLignes < uiMATNbLignes; uiCptLignes++)
	{
		for (uiCptColonnes = 0; uiCptColonnes < uiMATNbColonnes; uiCptColonnes++)
		{
			cout << pptpmMATMatrice[uiCptLignes][uiCptColonnes] << " ";
		}
		cout << endl;
	}
}
template <class TypeMatrice>
unsigned int CMatrice<TypeMatrice>::MATLireNbLignes()
{
	return uiMATNbLignes;
}
template <class TypeMatrice>
unsigned int CMatrice<TypeMatrice>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}

template <class TypeMatrice>
TypeMatrice CMatrice<TypeMatrice>::MATLireElement(unsigned int uinumLigne, unsigned int uinumColonne){

	return pptpmMATMatrice[uinumLigne - 1][uinumColonne - 1];
}

/* *************** Setter ************/
template <class TypeMatrice>
void CMatrice<TypeMatrice>::MATModifierElement(TypeMatrice tpmElement, unsigned int uinumLigne, unsigned int uinumColonne){
	pptpmMATMatrice[uinumLigne - 1][uinumColonne - 1] = tpmElement;
}

/* *************Operations **********/

//Surcharge =
template <class TypeMatrice>
CMatrice<TypeMatrice> CMatrice<TypeMatrice>::operator=(CMatrice<TypeMatrice>* MATParam){
	unsigned int uiLigne;
	unsigned int uiColonne;

	this = CMatrice<TypeMatrice>(&MATParam);

	return this;

}

 // Transposée
template <class TypeMatrice>
CMatrice<TypeMatrice> CMatrice<TypeMatrice>::MATTransposee()
{
	//CMatrice<int> * MTemp = new CMatrice<int>(uiMATNbLignes,uiMATNbColonnes);
	CMatrice<int> MTemp(uiMATNbLignes,uiMATNbColonnes);
	unsigned int uiLigne,uiColonne;
	/*unsigned int uiTransLigne=uiMATNbLignes-1;
	unsigned int uiTransColonne=uiMATNbColonnes-1;*/

	for(uiLigne = 0; uiLigne < uiMATNbLignes; uiLigne++){
		for(uiColonne=0; uiColonne<uiMATNbColonnes;uiColonne++)
			MTemp.pptpmMATMatrice[uiLigne][uiColonne]=pptpmMATMatrice[uiColonne][uiLigne];
	}

	return MTemp;
}

