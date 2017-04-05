#include "CMatrice.h"
#include "CParser.h"
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	//Création des matrice int 3x3 M1 (nulle) et M2 (123456789)
	cout << "Matrice nulle : " << endl;
	CMatrice<double> M1(3,3);
	CMatrice<double> M35(3,3);
	M35.MATModifierElement(1,1,1);
	M35.MATModifierElement(1,2,2);
	M35.MATModifierElement(1,3,3);
	CMatrice<double> M36(3,3);
	M36.MATModifierElement(1,1,1);
	M36.MATModifierElement(1,2,2);
	M36.MATModifierElement(1,3,3);
	
	M1.MATAfficherMatrice();
	CMatrice<double> M2(M1);
	M2.MATModifierElement(2,1,2);
	M2.MATModifierElement(3,1,3);
	M2.MATModifierElement(5,2,2);
	M2.MATModifierElement(8,3,2);
	M2.MATModifierElement(6,2,3);
	M2.MATModifierElement(1,1,1);
	M2.MATModifierElement(9,3,3);
	M2.MATModifierElement(7,3,1);
	M2.MATModifierElement(4,2,1);

	
	cout << "Multiplication" << endl;
	CMatrice<double> M63(M2 - M2);
	M63.MATAfficherMatrice();

	cout << "M1 + M2" << endl;
	M35.MATAfficherMatrice();
	
	M1.MATModifierElement(14,1,2);
	cout << "Matrice M1 : " << endl;
	M1.MATAfficherMatrice();

	//CParser P1;
	//P1.PARLireFichier("test1.txt");
	//cout << "Test 1 : Good" <<endl;
	//free(P1.getPpdPARMatrice());

	//début de l'algorithme
	/*double c;
	cout << "Saisir une valeur" << endl;
	cin >> c;
	cout << "Multiplication de M2 par ";
	cout << c ; cout << endl;
	CMatrice<double> M3(c * M2);
	cout << "Matrice M3 " << endl;
	M3.MATAfficherMatrice();
	cout << "Soustraction de M2 par M3 " << endl;
	CMatrice<double> M4(M2 - M3);
	M4.MATAfficherMatrice();
	cout << "Addition de M2 par M3 " << endl;
	CMatrice<double> M5(M2 + M3);
	M5.MATAfficherMatrice();
	cout << "Division de M2 par ";
	cout << c ; cout << endl;
	CMatrice<double> M6(c / M2);
	cout << "Matrice M6 " << endl;
	M6.MATAfficherMatrice();
	CMatrice<double> M7(3,3);
	M7.MATModifierElement(1,1,1);
	M7.MATModifierElement(1,2,2);
	M7.MATModifierElement(1,3,3);
	cout << "Matrice M7 " << endl;
	M7.MATAfficherMatrice();
	cout << "M7 * M2" << endl;
	CMatrice<double> M8(M7 * M2);
	M8.MATAfficherMatrice();
	CMatrice<double> M9(M2 + M3 + M7);
	M9.MATAfficherMatrice();*/

	return 0;
}