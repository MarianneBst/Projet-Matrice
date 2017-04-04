#include "CMatrice.h"
#include "CParser.h"
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	
	try{
		int uiCptArgs;
		int uiCptMatrice;
		CMatrice tMATTabMatrice[argc-1];
		for(uiCptArgs=1;uiCptArgs<argc;uiCptArgs++) // On parcourt les arguments pour remplir de tableau
		{
		
			CParser P1;
			cout << argv[uiCptArgs] << endl; 
			P1.PARLireFichier(argv[uiCptArgs]); //On parse le fichier en paramètre
			CMatrice<double> MP(P1); //On rempli le tableau avec la Matrice issue du fichier
			tMATTabMatrice[uiCptArgs]=MP;

			cout << "********************* MATRICE ISSUE DU PARSER *********************" << endl;
			MP.MATAfficherMatrice();
		}

		
			//début de l'algorithme
			int c;
			cout << "Saisir une valeur de type double (avec un . pour les decimales)" << endl;
			cin >> c;

			for(uiCptMatrice=0;uiCptMatrice<argc;uiCptMatrice++)
			{
				//Multiplication des matrices par c
				cout << "Multiplication de M" << uiCptMatrice+1 << " par " << c << " : " << endl;
				CMatrice<int> MTest(c * tMATTabMatrice[uiCptArgs]);
				M3.MATAfficherMatrice();

				//Division des matrices par c
				cout << "Division de M" << uiCptMatrice+1 << " par " << c << " : " << endl;
				CMatrice<int> MTest(c / M2);

				cout << "Soustraction de M2 par M3 " << endl;
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
				M9.MATAfficherMatrice();
	}catch(Cexception EXCObjet){
		EXCObjet.EXCLireMessage();	
	}
	}
	return 0;
}