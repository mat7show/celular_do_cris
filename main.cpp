#include <iostream>
#include <vector>

#include "syscelular.h"
using namespace tp2;

int main()
{
	std::cout << "lixo";
	
	Hora h;
	
	DataDMA um(30,6,2018);
	DataDMA hoje;
	std::cout << hoje.get_dia() << "/" << hoje.get_mes() << "/" << hoje.get_ano() << std::endl;

	std::cout << h.get_timestamp() << std::endl;


	if (um.valida()) std::cout << "d eh valido" << std::endl;
	if (hoje.valida()) std::cout << "hoje eh valido";

	std::vector<Cliente> clientes;
	std::vector<Celular*> cels;
	Interface Itau("Itau", clientes, cels);
	Itau.menu();
	
    return 0;
}

