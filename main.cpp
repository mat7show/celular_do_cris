#include <iostream> 
 
#include <vector> 
 
 
#include "syscelular.h"
 
using namespace tp2;
 
 
 
 int main()
 
 { 
 	 
 
 	 std::vector<Cliente> clientes; 
 
 	 std::vector<Celular*> cels; 
 
 	 Interface JMTelecom("JM", clientes, cels); 
	 JMTelecom.inicializa_numero(900);
 
 	 JMTelecom.menu(); 
 
 	 
 
     return 0 ; 
 
 } 
 
 
 
 
