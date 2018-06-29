#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include "syscelular.h"
using namespace std;
using namespace celular;


string DoubleToString(double d)
{
  std::ostringstream ss;
  ss << d;
  return ss.str();
}

string IntToString(int n)
{
  std::ostringstream ss;
  ss << n;
  return ss.str();
}



int Conta::proximoNumConta_ = 0;

Conta::Conta()
{
  Cliente gen;

  numConta_ = -1;
  cliente_ = gen;
  saldo_ = 0;
}

Conta::Conta(const Cliente &cliente)
{
  numConta_ = proximoNumConta_;
  proximoNumConta_++;
  cliente_ = cliente;
  saldo_ = 0;
}

int Conta::get_num_conta()const
{
  return numConta_;
}

double Conta::get_saldo()const
{
  return saldo_;
}

Cliente Conta::get_cliente()const
{
  return cliente_;
}

void Conta::debitar(double valor, std::string descr)
{
  Data agora;
  Movimentacao m(agora, descr, 'D', valor);

  if (!(saldo_ - valor < 0))
  {
    saldo_ -= valor;
  }
  movimentacoes_.push_back(m);
}
void Conta::atsaldo(double valor)
{
    saldo_ += valor;
}
void Conta::creditar(double valor, std::string descr)
{
  Data agora;
  Movimentacao m(agora, descr, 'C', valor);
  saldo_ += valor;
  movimentacoes_.push_back(m);
}

std::string Conta::get_extrato()const
{
  Data agora;
  std::string ret = "";
  for (size_t i = 0; i < movimentacoes_.size(); i++)
  {
    if (movimentacoes_[i].get_data_obj().get_ano() == agora.get_ano())
    {
      if (movimentacoes_[i].get_data_obj().get_mes() == agora.get_mes())
      {
        ret += movimentacoes_[i].get_data_obj().get_data_formatada(); ret += " ";
        ret += movimentacoes_[i].get_descricao(); ret += " ";
        ret += movimentacoes_[i].get_dc(); ret += " ";
        ret += movimentacoes_[i].get_valor_mov(); ret += "\n";
      }
    }
  }
  return ret;

}

//temq ser na forma certinha 'd/m/a' senao da ruim
std::string Conta::get_extrato(Data data)const
{
  std::string ret = "";
  for (size_t i = 0; i < movimentacoes_.size(); i++)
  {
    if (movimentacoes_[i].get_data_obj() >= data)
    {
      ret += movimentacoes_[i].get_data_obj().get_data_formatada(); ret += " ";
      ret += movimentacoes_[i].get_descricao(); ret += " ";
      ret += movimentacoes_[i].get_dc(); ret += " ";
      ret += movimentacoes_[i].get_valor_mov(); ret += "\n";
    }
  }
  return ret;
}


std::string Conta::get_extrato(Data datain, Data datasup)const
{
  std::string ret = "";
  for (size_t i = 0; i < movimentacoes_.size(); i++)
  {
    if (movimentacoes_[i].get_data_obj() >= datain)
    {
      if(movimentacoes_[i].get_data_obj() <= datasup)
      {
        ret += movimentacoes_[i].get_data_obj().get_data_formatada(); ret += " ";
        ret += movimentacoes_[i].get_descricao(); ret += "|";
        ret += movimentacoes_[i].get_dc(); ret += "|";
        ret += DoubleToString(movimentacoes_[i].get_valor_mov()); ret += "\n";
      }
    }
  }
  return ret;

}

std::string Conta::get_ficha_conta()const
{
  std::string ret = "";
  ret += IntToString(this->get_num_conta()) + "|";
  ret += DoubleToString(this->get_saldo()) + "|";
  ret += this->get_cliente().getcpf_cnpj();
  if(!movimentacoes_.empty())
  {
  for (size_t i = 0; i < movimentacoes_.size(); i++)
    {
      ret += "|";
      ret += movimentacoes_[i].get_data_obj().get_data_formatada() + "|";
      ret += movimentacoes_[i].get_descricao() + "|";
      ret += DoubleToString(movimentacoes_[i].get_valor_mov()); ret += "|";
      ret += movimentacoes_[i].get_dc();
    }
  }
  ret += "\n";
  return ret;
}

std::vector <Movimentacao> Conta::get_movimentacoes()
{
  return movimentacoes_;
}

void Conta::inserirMovimentacao(const Movimentacao &M)
{
  movimentacoes_.push_back(M);
}
