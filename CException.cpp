#include "CException.h"
#include <string.h>


/*********************
 * Constructeur par défaut 0 arg
 * *******************
 * Entrée : rien
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine : inititalisation de l'attribut cpEXCmessage
**********************/
CException::CException()
{
	cpEXCmessage = new char[20];
}

/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entrée : référence d'un objet
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine : inititalisation de l'objet en paramètre
**********************/
CException::CException(CException &objet)
{
	this->uiEXCValeur = objet.uiEXCValeur;
}

/*********************
 * Constructeur de paramètre 2 args
 * *******************
 * Entrée : uiValeur et cpMessage
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine : l'attribut uiEXCValeur et cpEXCmessage prend les valeurs en paramètre
**********************/
CException::CException(unsigned int uiValeur, char* cpMessage)
{
	uiEXCValeur = uiValeur;
	strcpy_s(cpEXCmessage, strlen(cpMessage) +1, cpMessage); 
	//strcpy(cpEXCmessage,cpEXCmessage);
	
}

/*********************
 * Destructeur 0 arg
 * *********************
 * Entrée : rien
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine : supprime l'attribut cpEXCmessage
**********************/
CException::~CException()
{
	delete cpEXCmessage;
}

/*********************
 * Méthode getter de l'erreur 0 arg
 * *********************
 * Entrée : rien
 * Nécessite : néant (?)
 * Sortie : l'attribut valeur
 * Entraine :
**********************/
unsigned int CException::EXCReadError()
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
char * CException::EXCReadMessage()
{
	return cpEXCmessage;
}

/*********************
 * Méthode setter message 1 arg
 * *********************
 * Entrée : cpMessage
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine :
**********************/
void CException::EXCwriteMessage(char* cpMessage)
{
    strcpy_s(cpEXCmessage, strlen(cpMessage) + 1, cpMessage);
}

/*********************
 * Méthode setter erreur 1 arg
 * *********************
 * Entrée : uiValeur
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine :
**********************/
void CException::EXCwriteError(unsigned int uiValeur)
{
	uiEXCValeur=uiValeur;
}
