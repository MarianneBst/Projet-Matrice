#include "string.h"
#include "stdlib.h"

class Cexception
{
	private:
		unsigned int uiEXCValeur;
		char* pcEXCmessage;

	public:
		Cexception(); //Constructeur par defaut
		Cexception(Cexception &EXCobjet); //de reocpie
		Cexception(unsigned  int uiValeur, char* pcMessage); // de confort
		~Cexception(); //Destructeur

		unsigned int EXCLireErreur(); //Accesseur lecture valeur erreur
		char * EXCLireMessage(); // Accesseur lecture message d'erreur 
		void EXCEcrireMessage(char* pcMessage); //Accesseur ecriture message
		void EXCEcrireErreur(unsigned int uiValeur); // Accesseur ecriture erreur

};

