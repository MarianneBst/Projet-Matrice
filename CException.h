#include "string.h"
#include "stdlib.h"

class Cexception
{
	private:
		unsigned int uiEXCValeur;
		char* cpEXCmessage;

	public:
		Cexception(); //Constructeur par defaut
		Cexception(Cexception &objet); //de reocpie
		Cexception(unsigned  int uiValeur, char* cpMessage); // de confort
		~Cexception(); //Destructeur

		unsigned int EXCReadError(); //Accesseur lecture valeur erreur
		char * EXCReadMessage(); // Accesseur lecture message d'erreur 
		void EXCwriteMessage(char* cpMessage); //Accesseur ecriture message
		void EXCwriteError(unsigned int uiValeur); // Accesseur ecriture erreur

};

