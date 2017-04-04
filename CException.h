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
 * Constructeur par défaut 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		Cexception();
/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entrée : objet de la classe Cexception
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		Cexception(Cexception &EXCobjet);
/*********************
 * Constructeur de paramètres 2 arg
 * *******************
 * Entrée : la valeur correspondant au type d'erreur et le message d'erreur
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		Cexception(unsigned  int uiValeur, char* pcMessage);
/*********************
 * Destructeur 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		~Cexception(); //Destructeur

/*********************
 * Accesseur en lecture de la valeur erreur 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : valeur du type de l'erreur
 * Postcondition : rien
**********************/
		unsigned int EXCLireErreur();
/*********************
 * Accesseur en lecture du message d'erreur 
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : message d'erreur
 * Postcondition : rien
**********************/
		char * EXCLireMessage();
/*********************
 * Accesseur ecriture du message d'erreur 
 * *******************
 * Entrée : message d'erreur
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		void EXCEcrireMessage(char* pcMessage);
/*********************
 * Accesseur ecriture de la valeur du type d'erreur 
 * *******************
 * Entrée : valeur d'erreur
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
		void EXCEcrireErreur(unsigned int uiValeur);

};
#endif

