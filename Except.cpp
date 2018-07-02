#include <string>
#include <stdexcept>

#include "syscelular.h"

using namespace tp2;

/*    
ideias boas pra excessoes:

--em construcoes de data com dia ou mes ou ano invalidos

--na funcao double to string e vice-versa, apenas o catch

*/





ExceptOpIleg::ExceptOpIleg(std::string e)
{
	erro_ = e;
}

std::string ExceptOpIleg::what()
{
	return erro_;
}


ExceptVetorCheio::ExceptVetorCheio(std::string e)
{
	erro_ = e;
}

std::string ExceptVetorCheio::what()
{
	return erro_;
}





ExceptData::ExceptData(std::string e)
{
	erro_ = e;
}

std::string ExceptData::what()
{
	return erro_;
}









ExceptOutras::ExceptOutras(std::string what) : runtime_error(what)
{
	erro_ = what;
}





