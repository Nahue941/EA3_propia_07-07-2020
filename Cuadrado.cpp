/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#include "Cuadrado.h"


Cuadrado::Cuadrado(double lado)
{
    if (lado<=0)
        throw FiguraInvalidaException();
    this->lado = lado;
}


double Cuadrado::area() const
{
	return this->lado * this->lado;
}
