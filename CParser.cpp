#include <iostream>
#include <fstream>

#include "CParser.h"
#include "Cexception.h"

using namespace std;

/*********************
 * Constructeur de paramètres 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
CParser::CParser()
{
	uiPARNbColonnes=0;
	uiPARNbLignes=0;
	ppdPARMatrice=NULL;
}

/*********************
 * Destructeur de paramètres 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
CParser::~CParser()
{
	free(ppdPARMatrice);
}

unsigned int CParser::getUiPARNbColonnes()
{
	return uiPARNbColonnes;
}

unsigned int CParser::getUiPARNbLignes()
{
	return uiPARNbLignes;
}

double** CParser::getPpdPARMatrice()
{
	return ppdPARMatrice;
}


void CParser::PARLireFichier(char* pcPath)
{
	//Ouvrir le fichier
	ifstream file(pcPath, ios::in);  // En lecture
	 
    if(file)  // si l'ouverture a réussi
	{
		//Parcours du fichier
		char tcLigne[1024]; //Chaine lue
		int iCpt=0; //Compteur de parcours de chaine
		int iCptIntermediaire=1; //Pour pouvoir l'utiliser pour le malloc
		char* pcGetterTemp=(char*)malloc(0); // Va servir à récupérer le nombre de lignes et de colonnes.
		char pcTypeMatrice[12]="TYPEMATRICE";
		char pcDouble[7]="DOUBLE";
		char pcNbColonnes[11]="NBCOLONNES";
		char pcNbLignes[9]="NBLIGNES";
		char pcMatrice[8]="MATRICE";
		unsigned int uiCptLignes, uiCptColonnes; //Compteur pour suivre le nombre de lignes et de colonnes.
		double dElementMatrice;
		char cTestCrochet;
		
		file.getline(tcLigne,1024);
		PARupperString(tcLigne);
		
/********************* TYPE MATRICE *********************/
		while(strstr(tcLigne,pcTypeMatrice)==NULL) //tant que "TypeMatrice" n'est pas dans la ligne, on continue.
		{
			file.getline(tcLigne,1024);
		    PARupperString(tcLigne);
		}

		if(strstr(tcLigne,pcDouble)==NULL) //Si dans la même ligne on ne trouve pas "double"
			{
				Cexception EXCObjet(10,"La matrice n'est pas de type double"); //Alors on jète une exception
				throw EXCObjet;
			}

		//Seek du curseur au début du fichier.
		file.seekg(0);

		file.getline(tcLigne,1024);
		PARupperString(tcLigne);

/********************* LIGNES *********************/
		while(strstr(tcLigne,pcNbLignes)==NULL) //tant que "NbLignes" n'est pas dans la ligne, on continue.
		{
			file.getline(tcLigne,1024);
		    PARupperString(tcLigne);
		}

		while(tcLigne[iCpt]!='=') //Tant qu'on à pas de =, on continue.
			iCpt++;

		iCpt++; //Nous sommes après le =

		while(tcLigne[iCpt]==' ')//On ignore les espaces après le '='
			iCpt++;

		
		if(isdigit(tcLigne[iCpt])!=0) //Si le caractère est un chiffre
		{
			while(tcLigne[iCpt]!=' ' && tcLigne[iCpt]!='\0')
			{
				pcGetterTemp=(char*)realloc(pcGetterTemp,iCptIntermediaire);
				pcGetterTemp[iCptIntermediaire-1]=tcLigne[iCpt];
				iCpt++;
				iCptIntermediaire++;
			}
		
			pcGetterTemp=(char*)realloc(pcGetterTemp,iCptIntermediaire);
			pcGetterTemp[iCptIntermediaire-1]='\0';  
			uiPARNbLignes=atoi(pcGetterTemp);
		}
		else
		{
			Cexception EXCObjet(11,"Le nombre de ligne n'est pas un nombre."); //Alors on jète une exception
			throw EXCObjet;
		}
		free(pcGetterTemp);
		file.seekg(0);

/********************* COLONNES *********************/
		file.getline(tcLigne,1024);
		PARupperString(tcLigne);
		iCpt=0;
		iCptIntermediaire=1;
		while(strstr(tcLigne,pcNbColonnes)==NULL) //tant que "NbColonnes" n'est pas dans la ligne, on continue.
		{
			file.getline(tcLigne,1024);
		    PARupperString(tcLigne);
		}

		while(tcLigne[iCpt]!='=') //Tant qu'on à pas de =, on continue.
			iCpt++;

		iCpt++; //Nous sommes après le =

		while(tcLigne[iCpt]==' ')//On ignore les espaces après le '='
			iCpt++;

		pcGetterTemp=(char*)malloc(0);
		if(isdigit(tcLigne[iCpt])!=0) //Si le caractère est un chiffre
		{
			while(tcLigne[iCpt]!=' ' && tcLigne[iCpt]!='\0')
			{
				pcGetterTemp=(char*)realloc(pcGetterTemp,iCptIntermediaire);
				pcGetterTemp[iCptIntermediaire-1]=tcLigne[iCpt];
				iCpt++;
				iCptIntermediaire++;
			}
			
			pcGetterTemp=(char*)realloc(pcGetterTemp,iCptIntermediaire);
			pcGetterTemp[iCptIntermediaire-1]='\0';  
			uiPARNbColonnes=atoi(pcGetterTemp);

		}
		else
		{
			Cexception EXCObjet(12,"Le nombre de colonnes n'est pas un nombre."); //Alors on jète une exception
			throw EXCObjet;
		}
		free(pcGetterTemp);
		file.seekg(0);


/********************* MATRICE *********************/
		ppdPARMatrice = new double* [uiPARNbLignes];
		for(uiCptLignes = 0; uiCptLignes < uiPARNbLignes; uiCptLignes++)
			ppdPARMatrice[uiCptLignes] = new double[uiPARNbColonnes];

		file.getline(tcLigne,1024);
		PARupperString(tcLigne);
		iCpt=0;
		while((strstr(tcLigne,pcTypeMatrice)!=NULL)||(strstr(tcLigne,pcMatrice)==NULL)) //tant que "Matrice" n'est pas dans la ligne, on continue.
		{
			file.getline(tcLigne,1024);
		    PARupperString(tcLigne);
		}

		while(tcLigne[iCpt]!='=') //Tant qu'on à pas de =, on continue.
			iCpt++;

		while(tcLigne[iCpt]!='[')//On attend le crochet ouvrant
			iCpt++;
		
		//Pour nbLignes
		for(uiCptLignes=0;uiCptLignes<uiPARNbLignes;uiCptLignes++)
		{
			//Tant que le compteur est inférieur au nb de colonne
				for (uiCptColonnes=0;uiCptColonnes<uiPARNbColonnes;uiCptColonnes++)
				{			
				//flux dans une var
				if(!(file >> dElementMatrice)) //Si l'élément n'est pas un double
				{
					Cexception EXCObjet(13,"L'élément n'est pas un double.");
					throw EXCObjet;
				}
				
				else
					ppdPARMatrice[uiCptLignes][uiCptColonnes]=dElementMatrice;
					
				}
			//Si il reste des caractère dans la ligne : erreur
				file.getline(tcLigne,1024); //On récupère la fin de la ligne.
				iCpt=0;
				
				while(tcLigne[iCpt]!='\0') //On parcourt cette ligne
				{
					if(tcLigne[iCpt]!=' ' || tcLigne[iCpt]!='\t') //Si il y a autre chose qu'un espace ou qu'une tabulation
					{
						Cexception EXCObjet(14,"Il y a plus d'élément que de colonnes"); //Alors il y a une erreur
						throw EXCObjet;
					}
					else
						iCpt++; //Sinon on continue de parcourir la chaine.
				}
				
		}
		file >> cTestCrochet;
		if(cTestCrochet!=']')
		{
			Cexception EXCObjet(15,"Trop de ligne ou caractère de fin incorrect"); //Alors il y a une erreur
			throw EXCObjet;
		}
	
	}

	else
		cerr << "Erreur ouverture fichier \n";
}

void CParser::PARupperString(char* pcString)
{
	while(*pcString != '\0')
	{
		*pcString=toupper(*pcString);
		pcString+=1;
	}

}
