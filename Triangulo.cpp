/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#include "Triangulo.h"


Triangulo::Triangulo(double base,double altura)
{
    if (base<=0 || altura<=0)
        throw FiguraInvalidaException();
    //Tecnicamente no es necesario que maneje esta excepcion para que el programa devuelva la salida esperada.
    //Pero lo hago para que teoricamente seria algo a tener en cuenta.
    //No seria necesari porque ni bien ocurra una excepcion el programa corta la ejecucion y maneja esa excepecion
    //por ende nunca llegaria a intentar crear un objeto triangulo con medidas negativas.

    this->base = base;
    this->altura = altura;
}


double Triangulo::area() const
{
	return (this->base * this->altura)/2;
}
