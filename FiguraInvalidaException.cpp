/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#include "FiguraInvalidaException.h"

FiguraInvalidaException::FiguraInvalidaException()
:exception()
{

}

const char* FiguraInvalidaException::what()
{
    return "Figura invalida";
}
