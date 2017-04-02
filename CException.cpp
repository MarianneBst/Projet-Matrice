#include "Cexception.h"
#include <string.h>


/*********************
 * Constructeur par d�faut 0 arg
 * *******************
 * Entr�e : rien
 * N�cessite : n�ant (?)
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
 * Entr�e : r�f�rence d'un objet
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine : inititalisation de l'objet en param�tre
**********************/
Cexception::Cexception(Cexception &objet)
{
	this->uiEXCValeur = objet.uiEXCValeur;
}

/*********************
 * Constructeur de param�tre 2 args
 * *******************
 * Entr�e : uiValeur et cpMessage
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine : l'attribut uiEXCValeur et cpEXCmessage prend les valeurs en param�tre
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
 * Entr�e : rien
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine : supprime l'attribut cpEXCmessage
**********************/
Cexception::~Cexception()
{
	delete cpEXCmessage;
}

/*********************
 * M�thode getter de l'erreur 0 arg
 * *********************
 * Entr�e : rien
 * N�cessite : n�ant (?)
 * Sortie : l'attribut valeur
 * Entraine :
**********************/
unsigned int Cexception::EXCReadError()
{
	return uiEXCValeur;
}

/*********************
 * M�thode getter du message 0 arg
 * *********************
 * Entr�e : rien
 * N�cessite : n�ant (?)
 * Sortie : l'attribut message
 * Entraine :
**********************/
char * Cexception::EXCReadMessage()
{
	return cpEXCmessage;
}

/*********************
 * M�thode setter message 1 arg
 * *********************
 * Entr�e : cpMessage
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine :
**********************/
void Cexception::EXCwriteMessage(char* cpMessage)
{
    strcpy_s(cpEXCmessage, strlen(cpMessage) + 1, cpMessage);
}

/*********************
 * M�thode setter erreur 1 arg
 * *********************
 * Entr�e : uiValeur
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine :
**********************/
void Cexception::EXCwriteError(unsigned int uiValeur)
{
	uiEXCValeur=uiValeur;
}
