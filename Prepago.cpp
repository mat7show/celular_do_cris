#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
#include <list>

using namespace std;
using namespace tp2;

static int custo_p_min = 3;

Prepago::Prepago (string numero,const Cliente &dono, vector<Ligacao> listaChamadas,double creditos,const DataDMA &validade ):Celular(numero, dono, listaChamadas)
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




void Prepago::set_creditos(double creditos)
{
	this->creditos_ = creditos;
}

void Prepago::set_validade(const DataDMA &validade)
{
	this->validade_ = validade;
}



string Celular::get_plano()
{
	return "Pre-pago";
}

void Celular::realizar_chamada(DataDMA dataLig, int duracao, Hora horalig)
{
	if (duracao*custo_p_min > get_creditos())
	{
		throw ExceptCreditoIns("Creditos insuficientes para a chamada");
	}
	Ligacao L(dataLig, duracao, horalig);
	listaChamadas_.push_back(L);
}
