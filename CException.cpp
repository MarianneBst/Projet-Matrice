#include "Cexception.h"
#include <string.h>


/*********************
 * Constructeur par défaut 0 arg
 * *******************
 * Entrée : rien
 * Nécessite : néant (?)
 * Sortie : rien
 * Entraine : inititalisation de l'attribut cpEXCmessage
**********************/
Cexception::Cexception()
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
Cexception::Cexception(Cexception &objet)
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
Cexception::Cexception(unsigned int uiValeur, char* cpMessage)
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
Cexception::~Cexception()
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
unsigned int Cexception::EXCReadError()
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
char * Cexception::EXCReadMessage()
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
void Cexception::EXCwriteMessage(char* cpMessage)
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
void Cexception::EXCwriteError(unsigned int uiValeur)
{
	uiEXCValeur=uiValeur;
}
