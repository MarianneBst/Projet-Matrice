#include "Cexception.h"
#include <string.h>


/*********************
 * Constructeur par défaut 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
Cexception::Cexception()
{
	pcEXCmessage = new char[200];//pas d'autre manière ?
}

/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entrée : objet de la classe Cexception
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
Cexception::Cexception(Cexception &EXCobjet)
{
	this->uiEXCValeur = EXCobjet.EXCLireErreur();
	pcEXCmessage = new char[200];
	strcpy_s(pcEXCmessage, strlen(EXCobjet.EXCLireMessage()) +1, EXCobjet.EXCLireMessage());
}

/*********************
 * Constructeur de paramètres 2 arg
 * *******************
 * Entrée : la valeur correspondant au type d'erreur et le message d'erreur
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
Cexception::Cexception(unsigned int uiValeur, char* pcMessage)
{
	uiEXCValeur = uiValeur;
	strcpy_s(pcEXCmessage, strlen(pcMessage) +1, pcMessage); 
	//strcpy(pcEXCmessage,pcEXCmessage);
	
}

/*********************
 * Destructeur 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
Cexception::~Cexception()
{
	delete pcEXCmessage;
}

/*********************
 * Accesseur en lecture de la valeur erreur 0 arg
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : valeur du type de l'erreur
 * Postcondition : rien
**********************/
unsigned int Cexception::EXCLireErreur()
{
	return uiEXCValeur;
}

/*********************
 * Accesseur en lecture du message d'erreur 
 * *******************
 * Entrée : rien
 * Précondition : rien
 * Sortie : message d'erreur
 * Postcondition : rien
**********************/
char * Cexception::EXCLireMessage()
{
	return pcEXCmessage;
}

/*********************
 * Accesseur ecriture du message d'erreur 
 * *******************
 * Entrée : message d'erreur
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
void Cexception::EXCEcrireMessage(char* pcMessage)
{
    strcpy_s(pcEXCmessage, strlen(pcMessage) + 1, pcMessage);
}

/*********************
 * Accesseur ecriture de la valeur du type d'erreur 
 * *******************
 * Entrée : valeur d'erreur
 * Précondition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
void Cexception::EXCEcrireErreur(unsigned int uiValeur)
{
	uiEXCValeur=uiValeur;
}
