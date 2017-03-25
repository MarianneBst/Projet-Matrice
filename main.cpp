#include "CMatrice.h"
#include "COperations.h"
#include "CException.h"
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	CMatrice<int> M1(3,3);
	M1.MATAfficherMatrice();
	CMatrice<int> M2(M1);
	//M2.MATModifierElement(17,0,2);
	//M2.MATAfficherMatrice();

	
	return 0;
}