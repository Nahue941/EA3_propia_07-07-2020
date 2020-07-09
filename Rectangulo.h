/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Figura.h"

class Rectangulo : public Figura
{
	private:
		double lado1, lado2;

	public:
		Rectangulo(double lado1,double lado2);
		double area() const;
};





#endif // RECTANGULO_H_
