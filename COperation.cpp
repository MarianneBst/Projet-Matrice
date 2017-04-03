#include "CMatrice.h"

/* préconditions pour la taille des matrices */ 
template <class TypeMatrice>
CMatrice<TypeMatrice> operator+(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	if(MATParamA.MATLireNbColonnes() != MATParamB.MATLireNbLignes()){
		Cexception EXCobjet(2, "Multiplication des matrices impossible");
		throw EXCobjet;
	}
	CMatrice<int> MTemp(MATParamA.MATLireNbLignes(),MATParamA.MATLireNbColonnes());
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	try{

		for(uiCptLignes = 1; uiCptLignes <= MATParamA.MATLireNbLignes(); uiCptLignes++)
		{
			for (uiCptColonnes = 1; uiCptColonnes <= MATParamA.MATLireNbColonnes() ;uiCptColonnes++)
				MTemp.MATModifierElement(MATParamA.MATLireElement(uiCptLignes,uiCptColonnes) + MATParamB.MATLireElement(uiCptLignes,uiCptColonnes),uiCptLignes,uiCptColonnes);
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}
	return MTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator-(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	
	CMatrice<int> MTemp(MATParamA.MATLireNbLignes(),MATParamA.MATLireNbColonnes());
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	
	try{

		for(uiCptLignes = 1; uiCptLignes <= MATParamA.MATLireNbLignes(); uiCptLignes++)
		{
			for (uiCptColonnes = 1; uiCptColonnes <= MATParamA.MATLireNbColonnes() ;uiCptColonnes++)
				MTemp.MATModifierElement(MATParamA.MATLireElement(uiCptLignes,uiCptColonnes) - MATParamB.MATLireElement(uiCptLignes,uiCptColonnes),uiCptLignes,uiCptColonnes);
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}
	
	return MTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	unsigned int uiCptSommes;
	TypeMatrice tpmSomme;
	CMatrice<int> MTemp(MATParamA.MATLireNbLignes(),MATParamB.MATLireNbColonnes());
	
	try{
		for(uiCptLignes = 1; uiCptLignes <= MATParamA.MATLireNbLignes(); uiCptLignes++)
		{
			for (uiCptColonnes = 1; uiCptColonnes <= MATParamB.MATLireNbColonnes() ; uiCptColonnes++)
			{
				//initialisation de tpmSomme
				tpmSomme = MATParamA.MATLireElement(uiCptLignes, 1) * MATParamB.MATLireElement(1, uiCptColonnes);
				for(uiCptSommes = 2; uiCptSommes <= MATParamA.MATLireNbColonnes() ; uiCptSommes++){
					tpmSomme = tpmSomme + MATParamA.MATLireElement(uiCptLignes, uiCptSommes) * MATParamB.MATLireElement(uiCptSommes, uiCptColonnes);
				}
				MTemp.MATModifierElement(tpmSomme, uiCptLignes, uiCptColonnes);
			}
		}
		
	}
	catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}
	return MTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATobjet, TypeMatrice fCoeff)
{
	unsigned int uiLigne;
	unsigned int uiColonne;
	int temp = 0;
	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());

	try{

		for(uiLigne = 1; uiLigne <= MATobjet.MATLireNbLignes(); uiLigne++){ // on initialise à 1 car la ligne 0 d'une matrice n'existe pas et retourne une exception
			for(uiColonne = 1; uiColonne <= MATobjet.MATLireNbColonnes() ; uiColonne++){
				MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne) * fCoeff, uiLigne, uiColonne);
			}
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}

	return MATTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(CMatrice<TypeMatrice> MATobjet, TypeMatrice fCoeff)
{
	unsigned int uiLigne;
	unsigned int uiColonne;
	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());
	
	try{

		for(uiLigne = 1; uiLigne <= MATobjet.MATLireNbLignes(); uiLigne++){
			for(uiColonne = 1; uiColonne <= MATobjet.MATLireNbColonnes() ; uiColonne++)
				MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne)/fCoeff, uiLigne, uiColonne);
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}

	return MATTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(TypeMatrice fCoeff, CMatrice<TypeMatrice> MATobjet)
{
	unsigned int uiLigne;
	unsigned int uiColonne;
	int temp = 0;
	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());

	try{

		for(uiLigne = 1; uiLigne <= MATobjet.MATLireNbLignes(); uiLigne++){ // on initialise à 1 car la ligne 0 d'une matrice n'existe pas et retourne une exception
			for(uiColonne = 1; uiColonne <= MATobjet.MATLireNbColonnes() ; uiColonne++){
				MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne) * fCoeff, uiLigne, uiColonne);
			}
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}

	return MATTemp;
}

template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(TypeMatrice fCoeff, CMatrice<TypeMatrice> MATobjet)
{
	unsigned int uiLigne;
	unsigned int uiColonne;
	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());

	try{

		for(uiLigne = 1; uiLigne <= MATobjet.MATLireNbLignes(); uiLigne++){
			for(uiColonne = 1; uiColonne <= MATobjet.MATLireNbColonnes() ; uiColonne++)
				MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne)/fCoeff, uiLigne, uiColonne);
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}

	return MATTemp;
}