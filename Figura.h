/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include "FiguraInvalidaException.h"

#include <string>

using namespace std;


class Figura
{
	public:
	    //Destructor
	    virtual ~Figura();
	    //Metodos
		virtual double area() const = 0;
};

#endif // FIGURA_H_
