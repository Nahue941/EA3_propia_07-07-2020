/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#include "Rectangulo.h"

Rectangulo::Rectangulo(double lado1,double lado2)
{
    this->lado1=lado1;
    this->lado2=lado2;
}


double Rectangulo::area() const
{
	return this->lado1 * this->lado2;
}
