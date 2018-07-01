#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
using namespace operadora;

Ligacao::Ligacao(DataDMA dataLig, int duracao, Hora horalig)
{
  data_ligacao_ = dataLig;
  hora_ligacao_ = horalig;
  duracao_ = duracao;

}

Ligacao::Ligacao(const Ligacao &M)
{
	data_ligacao_ = M.data_ligacao_;
	hora_ligacao_ = M.hora_ligacao_;
	duracao_ = M.duracao_;
}

DataDMA Ligacao::get_data_ligacao()const
{
  return data_ligacao_;
}



Hora Ligacao::get_hora_ligacao()const
{
	return hora_ligacao_;
}

int Ligacao::get_duracao()const
{
  return duracao_;
}
