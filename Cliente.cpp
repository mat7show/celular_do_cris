#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
using namespace std;
using namespace tp2;

Cliente::Cliente(string name, string id, string add)
{
	this->nomeCliente = name;
	this->cpf_cnpj_ = id;
	this->endereco = add;

}
Cliente::Cliente()
{
  this->nomeCliente = "default";
  this->cpf_cnpj_ = "default";
  this->endereco = "default";

}

Cliente::Cliente(const Cliente &a)
{
  this->nomeCliente = a.nomeCliente;
  this->cpf_cnpj_ = a.cpf_cnpj_;
  this->endereco = a.endereco;
}

string Cliente::getnomeCliente ()const
{
return nomeCliente;
}

string Cliente::getcpf_cnpj ()const
{
return cpf_cnpj_;
}

string Cliente::getendereco ()const
{
return endereco;
}


/*string Cliente::get_ficha()const
{
  return (this->getnomeCliente() + "|" + this->getcpf_cnpj()
  + "|" + this->getendereco() + "|" + this->getfone());
}*/

void Cliente::setnomeCliente(string name)
{
this->nomeCliente=name;
}
void Cliente::setcpf_cnpj(string id)
{
this->cpf_cnpj_=id;
}
void Cliente::setendereco(string add)
{
this->endereco =add;
}
