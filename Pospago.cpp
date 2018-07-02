#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"

using namespace std;
using namespace tp2;

Pospago::Pospago (string numero,const Cliente &dono, vector<Ligacao> listaChamadas,const DataDMA &vencimento, double fatura):Celular(numero, dono, listaChamadas)
{

vencimento_ = vencimento;
fatura_ = fatura;
}


DataDMA Pospago::get_vencimento ()const
{
	return vencimento_;
}




void Pospago::set_vencimento(const DataDMA &vencimento)
{
	this->vencimento_ = vencimento;
}


string Pospago::get_plano()
{
	return "Pos-pago";
}

double Pospago::get_fatura()const
{
	return fatura_;
}
void Pospago::set_fatura(double fatura)
{
	this->fatura_= fatura;
}

void Pospago::realizar_chamada(DataDMA dataLig, int duracao, Hora horalig)
{
	if (!dataLig.valida()) throw ExceptData("Data invalida");

	Ligacao L(dataLig, duracao, horalig);
	getlistaChamadas().push_back(L);
}

double Pospago::get_credfat()const
{
	return fatura_;
}

void Pospago::set_credfat(double fatura)
{
	fatura_ = fatura;
}
