#include "CMatrice.h"
#include "CParser.h"
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{

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
			cout << "Done";
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
			MAddSoustr = tMATTabMatrice[0];

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

				/*Probleme : Dans cette boucle doit se faire le calcul de l'addition. Sauf que la matrice  MAdd doit etre déclarée en dehors de la boucle
				(pour pas redéclarer à chaque itération) mais est construite en fonction du nombre de ligne de la matrice issue du tableau.
				2 solutions : 
					*Supposer que toutes les matrices ont la même taille que la première matrice par ex (donc mettable dans le constr de recopie)
					*Ne pas faire avec MAdd de cette manière */
				
				//Addition de toutes les matrices
					//On vérifie qu'elles ont la même taille pour pouvoir les additionner
				if(((tMATTabMatrice[uiCptMatrice].MATLireNbLignes()!=(tMATTabMatrice[uiCptMatrice+1].MATLireNbLignes()))
					|| (tMATTabMatrice[uiCptMatrice].MATLireNbColonnes()!=(tMATTabMatrice[uiCptMatrice+1].MATLireNbColonnes())))
					&& (uiCptMatrice<argc-2)){
					cout << " Tour " << uiCptMatrice << " & argc : " << argc-1 << endl;
					cout << tMATTabMatrice[uiCptMatrice].MATLireNbLignes() << " " << tMATTabMatrice[uiCptMatrice+1].MATLireNbLignes() << endl;
					cout << tMATTabMatrice[uiCptMatrice].MATLireNbColonnes() << " " << tMATTabMatrice[uiCptMatrice+1].MATLireNbColonnes() << endl;
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
				MMult.MATModifierElement(1,1,1);
				MMult.MATModifierElement(1,2,2);
				MMult.MATModifierElement(1,3,3); //On en fait une matrice identité

				MMult = MMult * tMATTabMatrice[uiCptMatrice];
			}

			cout << "Addition des " << uiCptMatrice << " matrices : " << endl;
			MAdd.MATAfficherMatrice();

			cout << "Multiplication des " << uiCptMatrice << " matrices : " << endl;
			MMult.MATAfficherMatrice();

			cout << "M1 - M2 + M3 - M4 + M5 ... etc : " << endl;
			MAddSoustr.MATAfficherMatrice();

			

				/*cout << "Soustraction de M2 par M3 " << endl;
				CMatrice<int> M4(M2 - M3);
				M4.MATAfficherMatrice();
				cout << "Addition de M2 par M3 " << endl;
				CMatrice<int> M5(M2 + M3);
				M5.MATAfficherMatrice();
				cout << "Division de M2 par ";
				cout << c ; cout << endl;
				CMatrice<int> M6(c / M2);
				cout << "Matrice M6 " << endl;
				M6.MATAfficherMatrice();
				CMatrice<int> M7(3,3);
				M7.MATModifierElement(1,1,1);
				M7.MATModifierElement(1,2,2);
				M7.MATModifierElement(1,3,3);
				cout << "Matrice M7 " << endl;
				M7.MATAfficherMatrice();
				cout << "M7 * M2" << endl;
				CMatrice<int> M8(M7 * M2);
				M8.MATAfficherMatrice();
				CMatrice<int> M9(M2 + M3 + M7);
				M9.MATAfficherMatrice();*/
			
	}catch(Cexception EXCObjet){
		EXCObjet.EXCLireMessage();	
	}
	
	return 0;
}