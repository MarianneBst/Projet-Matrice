#include "Cexception.h"
#include <string.h>


/*********************
 * Constructeur par d�faut 0 arg
 * *******************
 * Entr�e : rien
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
Cexception::Cexception()
{
	pcEXCmessage = new char[200];//pas d'autre mani�re ?
}

/*********************
 * Constructeur de recopie 1 arg
 * *******************
 * Entr�e : objet de la classe Cexception
 * Pr�condition : rien
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
 * Constructeur de param�tres 2 arg
 * *******************
 * Entr�e : la valeur correspondant au type d'erreur et le message d'erreur
 * Pr�condition : rien
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
 * Entr�e : rien
 * Pr�condition : rien
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
 * Entr�e : rien
 * Pr�condition : rien
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
 * Entr�e : rien
 * Pr�condition : rien
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
 * Entr�e : message d'erreur
 * Pr�condition : rien
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
 * Entr�e : valeur d'erreur
 * Pr�condition : rien
 * Sortie : rien
 * Postcondition : rien
**********************/
void Cexception::EXCEcrireErreur(unsigned int uiValeur)
{
	uiEXCValeur=uiValeur;
}
