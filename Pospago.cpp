#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
#include <list>

using namespace std;
using namespace operadora;

Pospago::Pospago (string numero,const Cliente &dono, list<Chamada> listaChamadas, double creditos,const DataDMA &vencimento):Celular(numero, dono, listaChamadas)
{
vencimento_ = vencimento;
plano=1;
}


DataDMA Pospago::get_vencimento ()const
{
return vencimento_;
}




void Pospago::set_vencimento(const DataDMA &vencimento)
{
this->vencimento_ = vencimento;
}

bool Pospago::get_plano()
{
  return plano;
}
