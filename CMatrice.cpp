#include "CMatrice.h"
#include "Cexception.h"


/* **********constructeurs **********/

/*********************
 * Constructeur par défaut 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice>::CMatrice()
{
	uiMATNbColonnes = 1;
	uiMATNbLignes = 1;
	pptpmMATMatrice = new TypeMatrice* [uiMATNbLignes];
	pptpmMATMatrice[0] = new TypeMatrice[uiMATNbColonnes];
	pptpmMATMatrice[0][0] = 0;
}

/*********************
 * Constructeur de paramètres 2 arg
 * *******************
 * Entrée : le nombre de lignes et de colonnes
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
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

/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entrée : objet de la classe CMatrice
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice>::CMatrice(CMatrice<TypeMatrice> &MATobjet){
	unsigned int uiLigne;
	unsigned int uiColonne;

	uiMATNbColonnes = MATobjet.uiMATNbColonnes;
	uiMATNbLignes = MATobjet.uiMATNbLignes;
	
	pptpmMATMatrice = new TypeMatrice* [MATobjet.uiMATNbLignes];
	for(uiLigne = 0; uiLigne < MATobjet.uiMATNbLignes; uiLigne++){
		pptpmMATMatrice[uiLigne] = new TypeMatrice[MATobjet.uiMATNbColonnes];
		for(uiColonne = 0; uiColonne < MATobjet.uiMATNbColonnes; uiColonne++){
			pptpmMATMatrice[uiLigne][uiColonne] = MATobjet.pptpmMATMatrice[uiLigne][uiColonne];
		}
	}
	
}

/* ************** Destructeurs **********/

/*********************
 * Destructeur 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice>::~CMatrice(){
	unsigned int uiLigne;

	for(uiLigne = 0; uiLigne < uiMATNbLignes; uiLigne++){
		delete[](pptpmMATMatrice[uiLigne]);
	}
	delete[](pptpmMATMatrice);
}


/* ************Getter *************/

/*********************
 * Accesseur en lecture de la matrice 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : la matrice
 * Postcondition : rien
**********************/
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

/*********************
 * Accesseur en lecture du nombre de lignes 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : nombre de lignes de la matrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
unsigned int CMatrice<TypeMatrice>::MATLireNbLignes()
{
	return uiMATNbLignes;
}

/*********************
 * Accesseur en lecture du nombre de colonnes 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : nombre de colonnes de la matrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
unsigned int CMatrice<TypeMatrice>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}

/*********************
 * Accesseur en lecture d'un élément de la matrice 2 arg
 * *******************
 * Entrée : le numéro de la ligne et de la colonne
 * Précondition : Les numéros de lignes commencent à 1 et ne doivent pas dépasser la taille de la matrice
 * Sortie : l'élément
 * Postcondition : rien
**********************/
template <class TypeMatrice>
TypeMatrice CMatrice<TypeMatrice>::MATLireElement(unsigned int uinumLigne, unsigned int uinumColonne){
	if(uinumLigne == 0 || uinumColonne == 0){
		Cexception EXCobjet(0, "Ligne ou colonne 0 inexistante");
		throw EXCobjet;
	}
	if(uinumLigne > uiMATNbLignes || uinumColonne > uiMATNbColonnes){
		Cexception EXCobjet(1, "Ligne ou colonne hors de la matrice");
		throw EXCobjet;
	}
	return pptpmMATMatrice[uinumLigne - 1][uinumColonne - 1];
}

/* *************** Setter ************/

/*********************
 * Accesseur en écriture d'un élément de la matrice 3 arg
 * *******************
 * Entrée : le nouvel élément le numéro de la ligne et de la colonne
 * Précondition : Les numéros de lignes commencent à 1 et ne doivent pas dépasser la taille de la matrice
 * Sortie : nombre de colonnes de la matrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
void CMatrice<TypeMatrice>::MATModifierElement(TypeMatrice tpmElement, unsigned int uinumLigne, unsigned int uinumColonne){
	if(uinumLigne == 0 || uinumColonne == 0){
		Cexception EXCobjet(0, "Ligne ou colonne 0 inexistante");
		throw EXCobjet;
	}
	if(uinumLigne > uiMATNbLignes || uinumColonne > uiMATNbColonnes){
		Cexception EXCobjet(1, "Ligne ou colonne hors de la matrice");
		throw EXCobjet;
	}
	pptpmMATMatrice[uinumLigne - 1][uinumColonne - 1] = tpmElement;
}

/* *************Operations **********/

/*********************
 * Transposée d'une matrice 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : la matrice transposée
 * Postcondition : rien
**********************/

 // Transposée
//template <class TypeMatrice>
//CMatrice<TypeMatrice> CMatrice<TypeMatrice>::MATTransposee()
//{
//	CMatrice<TypeMatrice> MTemp(uiMATNbLignes,uiMATNbColonnes);
//	unsigned int uiLigne,uiColonne;
//
//	for(uiLigne = 1; uiLigne <= uiMATNbLignes; uiLigne++){
//		for(uiColonne = 1; uiColonne <= uiMATNbColonnes;uiColonne++)
//			MTemp.MATModifierElement(pptpmMATMatrice[uiColonne][uiLigne], uiLigne, uiColonne);
//	}
//
//	return MTemp;
//}

/*********************
 * Surcharge de l'opérateur = 0 arg
 * *******************
 * Entrée : un objet de la classe CMatrice
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
template <typename TypeMatrice>
void CMatrice<TypeMatrice>::operator=(CMatrice<TypeMatrice> &MATParam){
	
	//On détruit l'objet
	unsigned int uiLigne;

	for(uiLigne = 0; uiLigne < uiMATNbLignes; uiLigne++){
		delete[](pptpmMATMatrice[uiLigne]);
	}
	delete[](pptpmMATMatrice);
	
	unsigned int uiColonne;
	
	uiMATNbColonnes = MATParam.MATLireNbLignes();
	uiMATNbLignes = MATParam.MATLireNbColonnes();
	
	pptpmMATMatrice = new TypeMatrice* [MATParam.MATLireNbLignes()];
	for(uiLigne = 0; uiLigne < MATParam.MATLireNbLignes(); uiLigne++){
		pptpmMATMatrice[uiLigne] = new TypeMatrice[MATParam.MATLireNbColonnes()];
		for(uiColonne = 1; uiColonne <= uiMATNbColonnes;uiColonne++){
			MATModifierElement(MATParam.MATLireElement(uiLigne+1,uiColonne), uiLigne+1, uiColonne);
		}
	}
	
}
