/**//* 38.455.227-PAIVA_GORDILLO,NahuelAlejo-(01-2964) *//**/

#ifndef FIGURAINVALIDAEXCEPTION_H_
#define FIGURAINVALIDAEXCEPTION_H_

#include <string>

using namespace std;


class FiguraInvalidException
{
	private:
		string mensaje;

	public:
		FigraInvalidException(const string& mensaje);

		const string& getMensaje() const;
};

FiguraInvalidException::FiguraInvalidException(const string& mensaje)
{
	this->mensaje = mensaje;
}


const string& FiguraInvalidException::getMensaje() const
{
	return this->mensaje;
}



#endif // FIGURAINVALIDAEXCEPTION_H_
