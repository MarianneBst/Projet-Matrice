#include "COperations.h"
#include "CMatrice.h"

template <class TypeMatrice>
CMatrice<TypeMatrice> operator+(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	//faire une exception si la taille est différente
	CMatrice<int> MTemp(MATParamA.MATLireNbLignes(),MATParamA.MATLireNbColonnes());
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	
	for(uiCptLignes = 0; uiCptLignes < MATParamA.MATLireNbLignes(); uiCptLignes++)
	{
		for (uiCptColonnes = 0; uiCptColonnes < MATParamA.MATLireNbColonnes() ;uiCptColonnes++)
			MTemp.MATModifierElement(MATParamA.MATLireElement(uiCptLignes,uiCptColonnes) + MATParamB.MATLireElement(uiCptLignes,uiCptColonnes),uiCptLignes,uiCptColonnes);
	}

	return MTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator-(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	//faire une exception si la taille est différente
	CMatrice<int> MTemp(MATParamA.MATLireNbLignes(),MATParamA.MATLireNbColonnes());
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	
	for(uiCptLignes = 0; uiCptLignes < MATParamA.MATLireNbLignes(); uiCptLignes++)
	{
		for (uiCptColonnes = 0; uiCptColonnes < MATParamA.MATLireNbColonnes() ;uiCptColonnes++)
			MTemp.MATModifierElement(MATParamA.MATLireElement(uiCptLignes,uiCptColonnes) - MATParamB.MATLireElement(uiCptLignes,uiCptColonnes),uiCptLignes,uiCptColonnes);
	}

	return MTemp;
}

//template <class TypeMatrice>
//CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
//{
//
//	return 0;
//}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATobjet, TypeMatrice fCoeff)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());
	for(uiLigne = 0; uiLigne < MATobjet.MATLireNbLignes(); uiLigne++){
		for(uiColonne=0; uiColonne < MATobjet.MATLireNbColonnes() ; uiColonne++)
			MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne) * fCoeff, uiLigne, uiColonne);
	}

	return MATTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(CMatrice<TypeMatrice> MATobjet, TypeMatrice fCoeff)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());
	for(uiLigne = 0; uiLigne < MATobjet.MATLireNbLignes(); uiLigne++){
		for(uiColonne=0; uiColonne < MATobjet.MATLireNbColonnes() ; uiColonne++)
			MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne)/fCoeff, uiLigne, uiColonne);
	}

	return MATTemp;
}