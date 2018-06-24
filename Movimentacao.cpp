#include <iostream>
#include <string>
#include <vector>
#include "banksys.h"
using namespace banco;

Movimentacao::Movimentacao(Data dataMov, std::string descr, char dc, double valor)
{
  dataMov_ = dataMov;
  descricao_ = descr;
  debito_credito = dc;
  valor_ = valor;

}

Movimentacao::Movimentacao(const Movimentacao &M)
{
  dataMov_ = M.dataMov_;
  descricao_ = M.descricao_;
  debito_credito = M.debito_credito;
  valor_ = M.valor_;
}

Data Movimentacao::get_data_obj()const
{
  return dataMov_;
}

std::string Movimentacao::get_descricao()const
{
  return descricao_;
}

double Movimentacao::get_valor_mov()const
{
  return valor_;
}

char Movimentacao::get_dc()const
{
  return debito_credito;
}
