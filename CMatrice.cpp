#include "CMatrice.h"
#include "COperations.h"
#include "CException.h"


/* **********constructeurs **********/
//par d�faut
template <typename TypeMatrice>
CMatrice<TypeMatrice>::CMatrice()
{
	uiMATNbColonnes = 1;
	uiMATNbLignes = 1;
	pptpmMATMatrice = new TypeMatrice* [uiMATNbLignes];
	pptpmMATMatrice[0] = new TypeMatrice[uiMATNbColonnes];
	pptpmMATMatrice[0][0] = 0;
}

//de param�tres
template <typename TypeMatrice>
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
template <typename TypeMatrice>
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
template <typename TypeMatrice>
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
template <typename TypeMatrice>
unsigned int CMatrice<TypeMatrice>::MATLireNbLignes()
{
	return uiMATNbLignes;
}
template <typename TypeMatrice>
unsigned int CMatrice<TypeMatrice>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}

template <typename TypeMatrice>
TypeMatrice CMatrice<TypeMatrice>::MATLireElement(unsigned int uinumLigne, unsigned int uinumColonne){
	return pptpmMATMatrice[uiMATNbLignes][uiMATNbColonnes];
}

/* *************** Setter ************/
template <typename TypeMatrice>
void CMatrice<TypeMatrice>::MATModifierElement(TypeMatrice tpmElement, unsigned int uinumLigne, unsigned int uinumColonne){
	if(uinumLigne == 0 || uinumColonne == 0){
		CException EXCobjet(0, "Ligne ou colonne 0 inexistante");
		throw EXCobjet;
	}
	pptpmMATMatrice[uinumLigne - 1][uinumColonne - 1] = tpmElement;
}

/* *************Operations **********/

//Surcharge =
template <typename TypeMatrice>
CMatrice<TypeMatrice> CMatrice<TypeMatrice>::operator=(CMatrice<TypeMatrice>* MATParam){
	unsigned int uiLigne;
	unsigned int uiColonne;
	
	if(uiMATNbLignes != MATParam.MATLireNbLignes() || uiMATNbColonnes != MATParam.MATLireNbColonnes()){
		CException EXCobjet(2, "Les matrices ne sont pas de m�me taille");
		throw EXCobjet;
	}
	this = CMatrice<TypeMatrice>(&MATParam);

	return this;

}

////Surcharge * coeff
//template <typename TypeMatrice>
// CMatrice<TypeMatrice> CMatrice<TypeMatrice>::operator*(float fCoeff)
//{
//	CMatrice<int>* MTemp = new CMatrice<int>(uiMATNbColonnes,uiMATNbColonnes);
//	*MTemp = COperation<TypeMatrice>::OPEMultiplicationParCoeff(*this,fCoeff);
//	 
//	return MTemp;
//}
//
// //Surcharge / coeff
//template <typename TypeMatrice>
// CMatrice<TypeMatrice> CMatrice<TypeMatrice>::operator/(float fCoeff)
//{
//	CMatrice<int> MTemp = new CMatrice<int>(this.MATLireNbLignes,this.MATLireNbColonnes);
//	 MTemp = OPEDivisionParCoeff(this,MATParam);
//	 
//	 return MTemp;
//}
//
// //Surcharge +
// template <typename TypeMatrice>
// CMatrice<TypeMatrice> CMatrice<TypeMatrice>::operator+(CMatrice<TypeMatrice> MATParam)
// {
//	 CMatrice<int> MTemp = new CMatrice<int>(MATParam.MATLireNbLignes,MATParam.MATLireNbColonnes);
//	 MTemp = OPEAddition(this,MATParam);
//	 
//	 return MTemp;
// }
//
// //Surcharge -
// template <typename TypeMatrice>
// CMatrice<TypeMatrice> CMatrice<TypeMatrice>::operator-(CMatrice<TypeMatrice> MATParam)
// {
//	 CMatrice<int> MTemp = new CMatrice<int>(MATParam.MATLireNbLignesMATParam,MATParam.MATLireNbColonnes);
//	 MTemp = OPESoustraction(this,MATParam);
//	 
//	 return MTemp;
// }
//
// //Surcharge *
// template <typename TypeMatrice>
// CMatrice<TypeMatrice> CMatrice<TypeMatrice>::operator*(CMatrice<TypeMatrice> MATParam)
// {
//	 CMatrice<int> MTemp = new CMatrice<int>(this.MATLireNbLignes,MATParam.MATLireNbColonnes);
//	 MTemp = OPEMultiplication(this,MATParam);
//	 
//	 return MTemp;
// }

 // Transpos�e
template <typename TypeMatrice>
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

