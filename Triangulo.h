/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"

class Triangulo : public Figura
{
	private:
		double base;
		double altura;

	public:
		Triangulo(double base,double altura);
		double area() const;
};


#endif // TRIANGULO_H_
