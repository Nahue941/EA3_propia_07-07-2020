/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#ifndef FIGURAINVALIDAEXCEPTION_H_
#define FIGURAINVALIDAEXCEPTION_H_

#include <string.h>

class FiguraInvalidaException
{
    private:
        const char* mensaje;

    public:
        FiguraInvalidaException() : mensaje ("Figura invalida"){};
        const char* what() const throw() {return mensaje;};
};


#endif // FIGURAINVALIDAEXCEPTION_H_
