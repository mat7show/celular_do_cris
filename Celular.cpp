#include <string>
#include <vector>
#include <list>
#include "syscelular.h"
using namespace std;
using namespace celular;



Celular::Celular(string numero, const Cliente &dono, list<Chamada> listaChamadas, bool plano)
{
  this->numero_ = numero;
  this->dono_ = dono;
  this->listaChamadas_ = listaChamadas;
  this->plano_ = plano;

}


Celular::Celular(const Celular &a)
{
  this->numero_ = a.numero_;
  this->dono_ = a.dono_;
  this->listaChamadas_ = a.listaChamadas_;
  this->plano_ = a.plano_;
}
string Celular::getNumero ()const
{
return numero_;
}

Cliente Celular::getDono ()const
{
return dono_;
}

list<Chamada> Celular::getlistaChamadas ()const
{
return listaChamadas_;
}
bool Celular::getPlano()const{
  return plano_;
}


void Celular::setNumero(string numero)
{
this->numero_=numero;
}
void Celular::setDono(const Cliente &dono)
{
this->dono_ = dono;
}
void Celular::setlistaChamadas(list<Chamada> listaChamadas)
{
this->listaChamadas_ =listaChamadas;
}

void Celular::setPlano(bool plano)
{
  this->plano_=plano;
}
