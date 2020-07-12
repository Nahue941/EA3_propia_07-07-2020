/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#ifndef FIGURAINVALIDAEXCEPTION_H_
#define FIGURAINVALIDAEXCEPTION_H_

#include "Figura.h"
#include <exception>
using namespace std;

class FiguraInvalidaException : public exception
{
    public:
        FiguraInvalidaException();
        const char* what();
};


#endif // FIGURAINVALIDAEXCEPTION_H_
