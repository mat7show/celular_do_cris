#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
using namespace operadora;

Ligacao::Ligacao(DataDMA dataLig, int duracao)
{
  data_ligacao_ = dataLig;
  //TEMQ COLOCAR HORA_LIGACAO AQUI COMO ENTRADA
  //hora_ligacao = horalig;
  duracao_ = duracao;

}

Ligacao::Ligacao(const Ligacao &M)
{
	data_ligacao_ = M.data_ligacao_;
	//hora_ligacao = M.hora_ligacao;
	duracao_ = M.duracao_;
}

DataDMA Ligacao::get_data_ligacao()const
{
  return data_ligacao_;
}



//Hora get_hora_ligacao()const
//{
//	return hora_ligacao_
//}

int Ligacao::get_duracao()const
{
  return duracao_;
}
