#include "CMatrice.h"

/*********************
 * Surcharge de l'op�rateur + 2 arg
 * *******************
 * Entr�e : deux matrices
 * Pr�condition : il faut que les matrices soient de m�me dimensions
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator+(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	if(MATParamA.MATLireNbLignes() != MATParamB.MATLireNbLignes() && MATParamA.MATLireNbColonnes() != MATParamB.MATLireNbColonnes()){
		Cexception EXCobjet(2, "Addition des matrices impossible");
		throw EXCobjet;
	}
	CMatrice<TypeMatrice> MTemp(MATParamA.MATLireNbLignes(),MATParamA.MATLireNbColonnes());
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

/*********************
 * Surcharge de l'op�rateur - 2 arg
 * *******************
 * Entr�e : deux matrices
 * Pr�condition : il faut que les matrices soient de m�me dimensions
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator-(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	
	CMatrice<TypeMatrice> MTemp(MATParamA.MATLireNbLignes(),MATParamA.MATLireNbColonnes());
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;

	if(MATParamA.MATLireNbLignes() != MATParamB.MATLireNbLignes() && MATParamA.MATLireNbColonnes() != MATParamB.MATLireNbColonnes()){
		Cexception EXCobjet(2, "Soustraction des matrices impossible");
		throw EXCobjet;
	}
	
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

/*********************
 * Surcharge de l'op�rateur * 2 arg
 * *******************
 * Entr�e : deux matrices
 * Pr�condition : il faut que le nombre de colonnes de la matrice A soit �gal au nombre de lignes de la matrice B
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB)
{
	unsigned int uiCptColonnes;
	unsigned int uiCptLignes;
	unsigned int uiCptSommes;
	TypeMatrice tpmSomme;
	CMatrice<TypeMatrice> MTemp(MATParamA.MATLireNbLignes(),MATParamB.MATLireNbColonnes());

	if(MATParamA.MATLireNbColonnes() != MATParamB.MATLireNbLignes()){
		Cexception EXCobjet(2, "Multiplication des matrices impossible");
		throw EXCobjet;
	}
	
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

/*********************
 * Surcharge de l'op�rateur * 2 arg
 * *******************
 * Entr�e : une matrice et un coefficient
 * Pr�condition : le coefficient doit �tre de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(CMatrice<TypeMatrice> MATobjet, TypeMatrice tpmCoeff)
{
	unsigned int uiLigne;
	unsigned int uiColonne;
	int temp = 0;
	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());

	try{

		for(uiLigne = 1; uiLigne <= MATobjet.MATLireNbLignes(); uiLigne++){ // on initialise � 1 car la ligne 0 d'une matrice n'existe pas et retourne une exception
			for(uiColonne = 1; uiColonne <= MATobjet.MATLireNbColonnes() ; uiColonne++){
				MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne) * tpmCoeff, uiLigne, uiColonne);
			}
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}

	return MATTemp;
}

/*********************
 * Surcharge de l'op�rateur / 2 arg
 * *******************
 * Entr�e : une matrice et un coefficient
 * Pr�condition : le coefficient doit �tre de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(CMatrice<TypeMatrice> MATobjet, TypeMatrice tpmCoeff)
{
	unsigned int uiLigne;
	unsigned int uiColonne;
	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());
	
	try{

		for(uiLigne = 1; uiLigne <= MATobjet.MATLireNbLignes(); uiLigne++){
			for(uiColonne = 1; uiColonne <= MATobjet.MATLireNbColonnes() ; uiColonne++)
				MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne)/tpmCoeff, uiLigne, uiColonne);
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}

	return MATTemp;
}

/*********************
 * Surcharge de l'op�rateur * 2 arg
 * *******************
 * Entr�e : une matrice et un coefficient
 * Pr�condition : le coefficient doit �tre de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator*(TypeMatrice tpmCoeff, CMatrice<TypeMatrice> MATobjet)
{
	unsigned int uiLigne;
	unsigned int uiColonne;
	int temp = 0;
	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());

	try{

		for(uiLigne = 1; uiLigne <= MATobjet.MATLireNbLignes(); uiLigne++){ // on initialise � 1 car la ligne 0 d'une matrice n'existe pas et retourne une exception
			for(uiColonne = 1; uiColonne <= MATobjet.MATLireNbColonnes() ; uiColonne++){
				MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne) * tpmCoeff, uiLigne, uiColonne);
			}
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}

	return MATTemp;
}

/*********************
 * Surcharge de l'op�rateur / 2 arg
 * *******************
 * Entr�e : une matrice et un coefficient
 * Pr�condition : le coefficient doit �tre de Type Matrice
 * Sortie : objet de la classe CMatrice
 * Postcondition : rien
**********************/
template <class TypeMatrice>
CMatrice<TypeMatrice> operator/(TypeMatrice tpmCoeff, CMatrice<TypeMatrice> MATobjet)
{
	unsigned int uiLigne;
	unsigned int uiColonne;
	CMatrice<TypeMatrice> MATTemp(MATobjet.MATLireNbLignes(), MATobjet.MATLireNbColonnes());

	try{

		for(uiLigne = 1; uiLigne <= MATobjet.MATLireNbLignes(); uiLigne++){
			for(uiColonne = 1; uiColonne <= MATobjet.MATLireNbColonnes() ; uiColonne++)
				MATTemp.MATModifierElement(MATobjet.MATLireElement(uiLigne, uiColonne)/tpmCoeff, uiLigne, uiColonne);
		}
	}catch(Cexception EXCexception){
		cerr << EXCexception.EXCLireMessage();
	}

	return MATTemp;
}