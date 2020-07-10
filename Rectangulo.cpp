/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#include "Rectangulo.h"

Rectangulo::Rectangulo(double lado1,double lado2)
{
    if (lado1<=0 || lado2<=0)
        throw FiguraInvalidaException();
    //Tecnicamente no es necesario que maneje esta excepcion para que el programa devuelva la salida esperada.
    //Pero lo hago para que teoricamente seria algo a tener en cuenta.
    //No seria necesario porque nunca se intenta crear un objeto Rectangulo con medidas negativas o iguales a 0

    this->lado1=lado1;
    this->lado2=lado2;
}


double Rectangulo::area() const
{
	return this->lado1 * this->lado2;
}
