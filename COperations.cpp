#include "COperations.h"
#include "CMatrice.h"

template <class TypeMatrice>
CMatrice<TypeMatrice> COperation<TypeMatrice>::OPEAddition(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	CMatrice<int> MTemp = new CMatrice<int>(this.MATLireNbLignes(),this.MATLireNbColonnes());
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	
	for(uiCptLignes = 0; uiCptLignes < MATParamA.MATLireNbLignes(); uiCptLignes++)
	{
		for (uiCptColonnes = 0; uiCptColonnes < MATParamA.MATLireNbColonnes() ;uiCptColonnes++)
			MTemp[uiCptLignes][uiCptColonnes]=MATParamA[uiCptLignes][uiCptColonnes]+MATParamB[uiCptLignes][uiCptColonnes];
	}

	return MTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> COperation<TypeMatrice>::OPESoustraction(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	CMatrice<int> MTemp = new CMatrice<int>(this.MATLireNbLignes(),this.MATLireNbColonnes());
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	
	for(uiCptLignes = 0; uiCptLignes < MATParamA.MATLireNbLignes(); uiCptLignes++)
	{
		for (uiCptColonnes = 0; uiCptColonnes < MATParamA.MATLireNbColonnes() ;uiCptColonnes++)
			MTemp[uiCptLignes][uiCptColonnes]=MATParamA[uiCptLignes][uiCptColonnes]-MATParamB[uiCptLignes][uiCptColonnes];
	}

	return MTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> COperation<TypeMatrice>::OPEMultiplication(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	return 0;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> COperation<TypeMatrice>::OPEMultiplicationParCoeff(CMatrice<TypeMatrice> MATParam, float fcoeff)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	for(uiLigne = 0; uiLigne < uiMATNbLignes; uiLigne++){
		for(uiColonne=0; uiColonne<uiMATNbColonnes;uiColonne++)
			pptpmMATMatrice[uiLigne][uiColonne]=pptpmMATMatrice[uiColonne][uiLigne]*fCoeff;
	}

	return this;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> COperation<TypeMatrice>::OPEDivisionParCoeff(CMatrice<TypeMatrice> MATParam, float fcoeff)
{
	unsigned int uiLigne;
	unsigned int uiColonne;

	for(uiLigne = 0; uiLigne < uiMATNbLignes; uiLigne++){
		for(uiColonne=0; uiColonne<uiMATNbColonnes;uiColonne++)
			pptpmMATMatrice[uiLigne][uiColonne]=pptpmMATMatrice[uiColonne][uiLigne]/fCoeff;
	}

	return this;
}
