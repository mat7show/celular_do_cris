#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
#include <list>

using namespace std;
using namespace operadora;

Prepago::Prepago (string numero,const Cliente &dono, list<Chamada> listaChamadas,double creditos,const DataDMA &validade ) : Celular(numero, dono, listaChamadas)
{
creditos_ = creditos;
validade_=validade;
}

double Prepago::get_creditos ()const
{
return creditos_;
}
DataDMA Prepago::get_validade ()const
{
return validade_;
}
]

void Prepago::set_creditos(double creditos)
{
this->creditos_ = creditos;
}

void Prepago::set_creditos(const DataDMA &validade)
{
this->validade_ = validade;
}
