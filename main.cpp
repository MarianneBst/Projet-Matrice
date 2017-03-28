#include "CMatrice.h"
#include "COperations.cpp"
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
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
	
	cout << "Matrice M : " << endl;
	M2.MATAfficherMatrice();

	CMatrice<int> Mt(M2.MATTransposee());
	cout << "Matrice transpos�e de M : " << endl;
	Mt.MATAfficherMatrice();

	/*CMatrice<int> MMultCoeff(M2*2);
	cout << "Matrice transpos�e de M : " << endl;
	
	MMultCoeff.MATAfficherMatrice();*/

	int c;

	cout << "Saisir une valeur" << endl;
	cin >> c;
	cout << "Multiplication par ";
	cout << c ; cout << endl;
	CMatrice<int> M3(M2 * c);
	M3.MATAfficherMatrice();
	M1 = M2 - M3;







	
	return 0;
}