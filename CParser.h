#ifndef C_PARSER_H
#define C_PARSER_H
#include "CMatrice.h"
#include <iostream>

class CParser
{
private:
	unsigned int uiPARNbColonnes;
	unsigned int uiPARNbLignes;
	double** ppdPARMatrice;
public:
	CParser();
	~CParser();
	void PARLireFichier(char* pcPath);
	void PARupperString(char* pcString);
	unsigned int getUiPARNbColonnes();
	unsigned int getUiPARNbLignes();
	double** getPpdPARMatrice();

	
};
#endif C_PARSER_H
