#ifndef C_OPERATION_H
#define C_OPERATION_H

#include "CMatrice.h"

template <class TypeMatrice>
class COperation
{
public:
	static CMatrice<TypeMatrice> OPEAddition(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);//plutôt des objets en paramètre

	static CMatrice<TypeMatrice> OPESoustraction(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

	static CMatrice<TypeMatrice> OPEMultiplication(CMatrice<TypeMatrice> MATParamA, CMatrice<TypeMatrice> MATParamB);

	static CMatrice<TypeMatrice> OPEMultiplicationParCoeff(CMatrice<TypeMatrice> MATParam, float fcoeff);

	static CMatrice<TypeMatrice> OPEDivisionParCoeff(CMatrice<TypeMatrice> MATParam, float fcoeff);

};
#endif
