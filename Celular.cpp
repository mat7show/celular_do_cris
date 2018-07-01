#include <string>
#include <vector>
#include <list>
#include "syscelular.h"
using namespace std;
using namespace operadora;



Celular::Celular(string numero, const Cliente &dono, vector<Ligacao> listaChamadas)
{
  this->numero_ = numero;
  this->dono_ = dono;
  this->listaChamadas_ = listaChamadas;

}


Celular::Celular(const Celular &a)
{
  this->numero_ = a.numero_;
  this->dono_ = a.dono_;
  this->listaChamadas_ = a.listaChamadas_;
}
string Celular::getNumero ()const
{
return numero_;
}

Cliente Celular::getDono ()const
{
return dono_;
}

vector<Ligacao> Celular::getlistaChamadas ()const
{
return listaChamadas_;
}

void Celular::setNumero(string numero)
{
this->numero_=numero;
}
void Celular::setDono(const Cliente &dono)
{
this->dono_ = dono;
}
void Celular::setlistaChamadas(vector<Ligacao> listaChamadas)
{
this->listaChamadas_ =listaChamadas;
}

double Celular::get_creditos ()const{}
DataDMA Celular::get_validade ()const{}
void Celular::set_creditos(double creditos){}
void Celular::set_validade(const DataDMA &validade){}
DataDMA Celular::get_vencimento ()const{}
void Celular::set_vencimento(const DataDMA &vencimento){}
