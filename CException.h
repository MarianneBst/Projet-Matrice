#ifndef PROJETMATRICE_CEXCEPTION_H
#define PROJETMATRICE_CEXCEPTION_H


#include "string.h"
#include "stdlib.h"

class Cexception
{
	private:
		unsigned int uiEXCValeur;
		char* pcEXCmessage;

	public:
/*********************
 * Constructeur par d�faut 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		Cexception();
/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entr�e : objet de la classe Cexception
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		Cexception(Cexception &EXCobjet);
/*********************
 * Constructeur de param�tres 2 arg
 * *******************
 * Entr�e : la valeur correspondant au type d'erreur et le message d'erreur
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		Cexception(unsigned  int uiValeur, char* pcMessage);
/*********************
 * Destructeur 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		~Cexception(); //Destructeur

/*********************
 * Accesseur en lecture de la valeur erreur 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : valeur du type de l'erreur
 * Postcondition : rien
**********************/
		unsigned int EXCLireErreur();
/*********************
 * Accesseur en lecture du message d'erreur 
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : message d'erreur
 * Postcondition : rien
**********************/
		char * EXCLireMessage();
/*********************
 * Accesseur ecriture du message d'erreur 
 * *******************
 * Entr�e : message d'erreur
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		void EXCEcrireMessage(char* pcMessage);
/*********************
 * Accesseur ecriture de la valeur du type d'erreur 
 * *******************
 * Entr�e : valeur d'erreur
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		void EXCEcrireErreur(unsigned int uiValeur);

};
#endif

