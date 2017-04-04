#include "CMatrice.h"
#include "CParser.h"
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	try{
		//Création des matrice int 3x3 M1 (nulle) et M2 (123456789)
		cout << "Matrice nulle : " << endl;
		CMatrice<int> M1(3,3);
		M1.MATAfficherMatrice();
		CMatrice<int> M2(M1);
		M2.MATModifierElement(2,1,2);
		M2.MATModifierElement(3,1,3);
		M2.MATModifierElement(5,2,2);
		M2.MATModifierElement(8,3,2);
		M2.MATModifierElement(6,2,3);
		M2.MATModifierElement(1,1,1);
		M2.MATModifierElement(9,3,3);
		M2.MATModifierElement(7,3,1);
		M2.MATModifierElement(4,2,1);
	
		cout << "Matrice M2 : " << endl;
		M2.MATAfficherMatrice();

		CMatrice<int> Mt(M2.MATTransposee());
		cout << "Matrice transposée de M2 : " << endl;
		Mt.MATAfficherMatrice();

		CParser P1;
		P1.PARLireFichier("test1.txt");
		CMatrice<double> MP(P1);
		cout << "****************************** MATRICE ISSUE DU PARSER *******************************************" << endl;
		MP.MATAfficherMatrice();

		
		//début de l'algorithme
		int c;
		cout << "Saisir une valeur" << endl;
		cin >> c;
		cout << "Multiplication de M2 par ";
		cout << c ; cout << endl;
		CMatrice<int> M3(c * M2);
		cout << "Matrice M3 " << endl;
		M3.MATAfficherMatrice();
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
	return 0;
}