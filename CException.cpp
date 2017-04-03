#include "Cexception.h"
#include <string.h>


/*********************
 * Constructeur par défaut 0 arg
 * *******************
 * Entrée : rien
 * Nécessite : néant (?) précondition
 * Sortie : rien
 * Entraine : inititalisation de l'attribut pcEXCmessage (postcondition)
**********************/
Cexception::Cexception()
{
	pcEXCmessage = new char[20];//pas d'autre manière ?
}

/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entrée : référence d'un objet
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine : inititalisation de l'objet en paramètre
**********************/
Cexception::Cexception(Cexception &EXCobjet)
{
	this->uiEXCValeur = EXCobjet.EXCLireErreur();
	pcEXCmessage = new char[20];
	strcpy_s(pcEXCmessage, strlen(EXCobjet.EXCLireMessage()) +1, EXCobjet.EXCLireMessage());
}

/*********************
 * Constructeur de paramètre 2 args
 * *******************
 * Entrée : uiValeur et pcMessage
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine : l'attribut uiEXCValeur et pcEXCmessage prend les valeurs en paramètre
**********************/
Cexception::Cexception(unsigned int uiValeur, char* pcMessage)
{
	uiEXCValeur = uiValeur;
	strcpy_s(pcEXCmessage, strlen(pcMessage) +1, pcMessage); 
	//strcpy(pcEXCmessage,pcEXCmessage);
	
}

/*********************
 * Destructeur 0 arg
 * *********************
 * Entrée : rien
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine : supprime l'attribut pcEXCmessage
**********************/
Cexception::~Cexception()
{
	delete pcEXCmessage;
}

/*********************
 * Méthode getter de l'erreur 0 arg
 * *********************
 * Entrée : rien
 * Nécessite : néant (?)
 * Sortie : l'attribut valeur
 * Entraine :
**********************/
unsigned int Cexception::EXCLireErreur()
{
	return uiEXCValeur;
}

/*********************
 * Méthode getter du message 0 arg
 * *********************
 * Entrée : rien
 * Nécessite : néant (?)
 * Sortie : l'attribut message
 * Entraine :
**********************/
char * Cexception::EXCLireMessage()
{
	return pcEXCmessage;
}

/*********************
 * Méthode setter message 1 arg
 * *********************
 * Entrée : pcMessage
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine :
**********************/
void Cexception::EXCEcrireMessage(char* pcMessage)
{
    strcpy_s(pcEXCmessage, strlen(pcMessage) + 1, pcMessage);
}

/*********************
 * Méthode setter erreur 1 arg
 * *********************
 * Entrée : uiValeur
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine :
**********************/
void Cexception::EXCEcrireErreur(unsigned int uiValeur)
{
	uiEXCValeur=uiValeur;
}
