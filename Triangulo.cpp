/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#include "Triangulo.h"


Triangulo::Triangulo(double base,double altura)
{
    this->base = base;
    this->altura = altura;
}


double Triangulo::area() const
{
	return (this->base * this->altura)/2;
}
