#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
#include <list>

using namespace std;
using namespace operadora;

Pospago::Pospago (string numero,const Cliente &dono, vector<Ligacao> listaChamadas,const DataDMA &vencimento):Celular(numero, dono, listaChamadas)
{

vencimento_ = vencimento;

}


DataDMA Pospago::get_vencimento ()const
{
	return vencimento_;
}




void Pospago::set_vencimento(const DataDMA &vencimento)
{
	this->vencimento_ = vencimento;
}


string Celular::get_plano()
{
	return "Pos-pago";
}