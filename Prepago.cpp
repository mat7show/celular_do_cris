#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
#include <list>

using namespace std;
using namespace tp2;


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



string Prepago::get_plano()
{
	return "Pre-pago";
}

void Prepago::realizar_chamada(DataDMA dataLig, int duracao, Hora horalig)
{	
	if (!dataLig.valida()) throw ExceptData("Data invalida");

	if (duracao*custo_p_min > get_creditos())
	{
		throw ExceptOpIleg("Creditos insuficientes para a chamada");
	}
	try 
	{
		int novo_cred = get_creditos() - duracao * custo_p_min;
		set_creditos(novo_cred);
		Ligacao L(dataLig, duracao, horalig);
		getlistaChamadas().push_back(L);
	}

	catch (ExceptOutras e) 
	{
		2;
	};
}

double Prepago::get_credfat()const
{
	return creditos_;
}

void Prepago::set_credfat(double fatura)
{
	set_creditos(fatura);
}

int Prepago::get_custo_p_min()
{
	return custo_p_min;
}


void Prepago::set_vencimento(const DataDMA &vencimento)
{
	validade_ = vencimento;
}

DataDMA Prepago::get_vencimento()const
{
	return validade_;
}