#include <iostream>

#include "syscelular.h"
using namespace operadora;

int main()
{
	std::cout << "lixo";
	
	Hora h;
	
	DataDMA um(30,6,2018);
	DataDMA hoje;
	std::cout << hoje.get_dia() << "/" << hoje.get_mes() << "/" << hoje.get_ano() << std::endl;

	std::cout << h.get_timestamp() << std::endl;


	if (um.valida()) std::cout << "d eh valido";
	
	while (1);
    return 0;
}

