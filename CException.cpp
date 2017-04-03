#include "Cexception.h"
#include <string.h>


/*********************
 * Constructeur par d�faut 0 arg
 * *******************
 * Entr�e : rien
 * N�cessite : n�ant (?) pr�condition
 * Sortie : rien
 * Entraine : inititalisation de l'attribut pcEXCmessage (postcondition)
**********************/
Cexception::Cexception()
{
	pcEXCmessage = new char[20];//pas d'autre mani�re ?
}

/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entr�e : r�f�rence d'un objet
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine : inititalisation de l'objet en param�tre
**********************/
Cexception::Cexception(Cexception &EXCobjet)
{
	this->uiEXCValeur = EXCobjet.EXCLireErreur();
	pcEXCmessage = new char[20];
	strcpy_s(pcEXCmessage, strlen(EXCobjet.EXCLireMessage()) +1, EXCobjet.EXCLireMessage());
}

/*********************
 * Constructeur de param�tre 2 args
 * *******************
 * Entr�e : uiValeur et pcMessage
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine : l'attribut uiEXCValeur et pcEXCmessage prend les valeurs en param�tre
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
 * Entr�e : rien
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine : supprime l'attribut pcEXCmessage
**********************/
Cexception::~Cexception()
{
	delete pcEXCmessage;
}

/*********************
 * M�thode getter de l'erreur 0 arg
 * *********************
 * Entr�e : rien
 * N�cessite : n�ant (?)
 * Sortie : l'attribut valeur
 * Entraine :
**********************/
unsigned int Cexception::EXCLireErreur()
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
char * Cexception::EXCLireMessage()
{
	return pcEXCmessage;
}

/*********************
 * M�thode setter message 1 arg
 * *********************
 * Entr�e : pcMessage
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine :
**********************/
void Cexception::EXCEcrireMessage(char* pcMessage)
{
    strcpy_s(pcEXCmessage, strlen(pcMessage) + 1, pcMessage);
}

/*********************
 * M�thode setter erreur 1 arg
 * *********************
 * Entr�e : uiValeur
 * N�cessite : n�ant (?)
 * Sortie : rien
 * Entraine :
**********************/
void Cexception::EXCEcrireErreur(unsigned int uiValeur)
{
	uiEXCValeur=uiValeur;
}
