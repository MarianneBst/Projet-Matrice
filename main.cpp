#include "CMatrice.h"
#include "CParser.h"
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc<2)
	{
		cout << "Erreur, pas d'argument. Arret du programme.";
		exit(-1);
	}
	try{
		int uiCptArgs=argc;
		int uiCptMatrice;

		CMatrice<double> * tMATTabMatrice = new CMatrice<double>[argc];

		
		for(uiCptArgs=1;uiCptArgs<argc;uiCptArgs++) // On parcourt les arguments pour remplir de tableau
		{
		
			CParser P1;
			cout << argv[uiCptArgs] << endl; 
			P1.PARLireFichier(argv[uiCptArgs]); //On parse le fichier en paramètre
		
			CMatrice<double> * MP = new CMatrice<double>(P1); //Création de MP issue du fichier
		
			cout << "*** MATRICE M" << uiCptArgs-1<< " ***" << endl;
			MP->MATAfficherMatrice();

			tMATTabMatrice[uiCptArgs-1]=*MP; //Remplissage du tableau
			
			delete(MP);				
		}

		
			//début de l'algorithme
			double c;
			cout << "Saisir une valeur de type double (avec un . pour les decimales)" << endl;
			cin >> c;

			//Les matrices devront toutes avec la même taille si on veut les additionner et les multiplier en même temps
			CMatrice<double> MAdd(tMATTabMatrice[0].MATLireNbLignes(),tMATTabMatrice[0].MATLireNbColonnes());
			CMatrice<double> MMult(tMATTabMatrice[0].MATLireNbLignes(),tMATTabMatrice[0].MATLireNbColonnes());
			CMatrice<double> MAddSoustr(tMATTabMatrice[0].MATLireNbLignes(),tMATTabMatrice[0].MATLireNbColonnes());

			MAddSoustr = tMATTabMatrice[0]; //On prend la première matrice comme départ

			MMult.MATModifierElement(1,1,1);
			MMult.MATModifierElement(1,2,2);
			MMult.MATModifierElement(1,3,3); //On en fait une matrice identité

			for(uiCptMatrice=0;uiCptMatrice<argc-1;uiCptMatrice++)
			{
				//Multiplication des matrices par c
				cout << "Multiplication de M" << uiCptMatrice+1 << " par " << c << " : " << endl;
				CMatrice<double> MTemp(c * tMATTabMatrice[uiCptMatrice]);
				MTemp.MATAfficherMatrice();

				//Division des matrices par c
				cout << "Division de M" << uiCptMatrice+1 << " par " << c << " : " << endl;
				MTemp = tMATTabMatrice[uiCptMatrice] / c ;
				MTemp.MATAfficherMatrice();

				//Addition de toutes les matrices
					//On vérifie qu'elles ont la même taille pour pouvoir les additionner
				if(((tMATTabMatrice[uiCptMatrice].MATLireNbLignes()!=(tMATTabMatrice[uiCptMatrice+1].MATLireNbLignes()))
					|| (tMATTabMatrice[uiCptMatrice].MATLireNbColonnes()!=(tMATTabMatrice[uiCptMatrice+1].MATLireNbColonnes())))
					&& (uiCptMatrice<argc-2)){ //Si la matrice courante n'a pas la même taille que la suivante, et qu'on n'est pas à la dernière matrice
					Cexception EXCObjet(20,"Les matrices ne sont pas de même taille, on ne peut les additionner."); //Alors on jète une exception
					throw EXCObjet;
				}
				MAdd = MAdd + tMATTabMatrice[uiCptMatrice];

				//M1-M2+M3-M4+M5...					
				if((uiCptMatrice%2==0) && (uiCptMatrice<argc-2)) //Si on est sur M1,M3,M5
					MAddSoustr = MAddSoustr - tMATTabMatrice[uiCptMatrice+1]; //On soustrait la prochaine
				
				else if((uiCptMatrice%2!=0) && (uiCptMatrice<argc-2)) // Si on est sur M2,M4,M6...
					MAddSoustr = MAddSoustr + tMATTabMatrice[uiCptMatrice+1]; //On soustrait la prochaine
	
				//Produit des matrices
				MMult = MMult * tMATTabMatrice[uiCptMatrice];
			}

			cout << "Addition des " << uiCptMatrice << " matrices : " << endl;
			MAdd.MATAfficherMatrice();

			cout << "Multiplication des " << uiCptMatrice << " matrices : " << endl;
			MMult.MATAfficherMatrice();

			cout << "M1 - M2 + M3 - M4 + M5 ... etc : " << endl;
			MAddSoustr.MATAfficherMatrice();

	}catch(Cexception EXCObjet){
		EXCObjet.EXCLireMessage();	
	}
	
	return 0;
}