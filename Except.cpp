#include <string>

#include "syscelular.h"

using namespace tp2;

/*    
ideias boas pra excessoes:

--em construcoes de data com dia ou mes ou ano invalidos

--na funcao double to string e vice-versa, apenas o catch




*/

ExceptCreditoIns::ExceptCreditoIns(std::string e)
{
	erro_ = e;
}

std::string ExceptCreditoIns::what()
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


ExceptContaInex::ExceptContaInex(std::string e)
{
	erro_ = e;
}

std::string ExceptContaInex::what()
{
	return erro_;
}



