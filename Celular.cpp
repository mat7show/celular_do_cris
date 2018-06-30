#include <string>
#include <vector>
#include <list>
#include "syscelular.h"
using namespace std;
using namespace operadora;



Celular::Celular(string numero, const Cliente &dono, list<Chamada> listaChamadas)
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

list<Chamada> Celular::getlistaChamadas ()const
{
return listaChamadas_;
}

bool get_plano();

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
