#include "CMatrice.h"
#include "Cexception.h"


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
//Parser
template <class TypeMatrice>
CMatrice<TypeMatrice>::CMatrice(CParser &PARObjet)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	uiMATNbColonnes = PARObjet.getUiPARNbColonnes();
	uiMATNbLignes = PARObjet.getUiPARNbLignes();
	
	pptpmMATMatrice = new TypeMatrice* [PARObjet.getUiPARNbLignes()];
	for(uiLigne = 0; uiLigne < PARObjet.getUiPARNbLignes(); uiLigne++){
		pptpmMATMatrice[uiLigne] = new TypeMatrice[PARObjet.getUiPARNbColonnes()];
		for(uiColonne = 0; uiColonne < PARObjet.getUiPARNbColonnes(); uiColonne++){
			pptpmMATMatrice[uiLigne][uiColonne] = PARObjet.getPpdPARMatrice()[uiLigne][uiColonne];
		}
	}
}

/* ************** Destructeur **********/
template <class TypeMatrice>
CMatrice<TypeMatrice>::~CMatrice(){
	unsigned int uiLigne;

	for(uiLigne = 0; uiLigne < uiMATNbLignes; uiLigne++){
		delete[](pptpmMATMatrice[uiLigne]);
	}
	delete[](pptpmMATMatrice);
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

// surcharge du =
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
