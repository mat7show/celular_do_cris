#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "syscelular.h"
using namespace std;
using namespace celular;


Banco::Banco()
{
  nomeBanco_ = "JP&MA Chase";
}

Banco::Banco(std::string nome, std::vector<Cliente> clientes, std::vector<Conta> contas )
{
  clientes_ = clientes;
  contas_ = contas;
  nomeBanco_ = nome;
}

void Banco::inserirCliente(const Cliente &C)
{
  bool jaTemCPF = false;
  for(size_t i = 0; i < clientes_.size(); i++)
  {
    if (clientes_[i].getcpf_cnpj() == C.getcpf_cnpj())
    {
      jaTemCPF = true;
    }
  }
  if(!jaTemCPF)
  {
    clientes_.push_back(C);
  }

}

void Banco::criarConta( const Cliente &C)
{
  bool jaTemConta = false; //primeiro verifica se o cliente ja tem conta
  for(size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_cliente().getcpf_cnpj() == C.getcpf_cnpj())
    {
      jaTemConta = true;
    }
  }
  if (!jaTemConta)
  {
  Conta nova(C);
  contas_.push_back(nova);
  }
}

void Banco::excluirCliente(std::string cpf_cnpj)
{
  bool tem_conta = false;
  for (size_t j = 0;  j<contas_.size(); j++)
  {
    if (contas_[j].get_cliente().getcpf_cnpj() == cpf_cnpj)
    {
      tem_conta = true;
    }
  }
  if (!tem_conta)
  {
    for (size_t i = 0; i<clientes_.size(); i++)
    {
      if (clientes_[i].getcpf_cnpj() == cpf_cnpj)
      {
        Cliente aux = clientes_[clientes_.size() - 1];
        clientes_[i] = aux;
        clientes_.pop_back();
      }
    }
  }
}

void Banco::excluirConta(int numConta)
{
  for (size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      Conta aux = contas_[contas_.size() - 1];
      contas_[i] = aux;
      contas_.pop_back();
      break;
    }
  }
}

void Banco::deposito( int numConta,double valor)
{
  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      contas_[i].creditar(valor, "Deposito");
      break;
    }
  }
}

void Banco::saque(int numConta, double valor)
{
  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      contas_[i].debitar(valor, "Saque");
      break;
    }
  }

}

void Banco::transferencia(int numContaOrigem, int numContaDestino, double valor)
{
  std::ostringstream numeroStr;

  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numContaOrigem)
    {
      numeroStr << IntToString(numContaDestino);
      std::string texto = "Transferencia para a conta "
      + numeroStr.str();


      contas_[i].debitar(valor, texto);
      break;
    }
  }




  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numContaDestino)
    {
      numeroStr << IntToString(numContaOrigem);
      std::string texto = "Transferencia da conta "
      + numeroStr.str();
      contas_[i].creditar(valor, texto);
      break;
    }
  }
}

void Banco::cobrarTarifa()
{
  double tarifa = 15.0;
  for(size_t i = 0; i<contas_.size(); i++)
  {
    std::string texto = "Cobranca de tarifa";
    contas_[i].debitar(tarifa, texto);
  }
}

void Banco::cobrarCPMF()
{
Data hoje;
double cpmf=0;
std::vector <Movimentacao> movi ;

int dia = hoje.get_dia();
int mes = hoje.get_mes();
int ano = hoje.get_ano();
dia -=7;
if (dia <0)
{
  if(mes==2 || mes==4 || mes==6 || mes==8 || mes==9 || mes==11 )
  {
    dia+=31;
  }
  if(mes == 3)
  {
    dia+=28;
  }
  if(mes==3 || mes==5 || mes==7 || mes==10 || mes==12 )
  {
    dia+=30;
  }
  if(mes == 1)
  {
    dia+=31;
    mes=12;
    ano-=1;
  }
}

Data seteatras(dia,mes,ano);



  for(size_t i = 0; i<contas_.size(); i++)
  {
  movi = contas_[i].get_movimentacoes();
    for (size_t i = 0; i < movi.size(); i++)
      {
        if(movi[i].get_data_obj()>=hoje)
          if(movi[i].get_data_obj()<=seteatras)
            {
              cpmf+=movi[i].get_valor_mov()*0.38/100;
            }
      }
    std::string texto = "Cobranca de CPMF";
    contas_[i].debitar(cpmf, texto);
  }
}

double Banco::obterSaldo(int numConta)const
{
  for(size_t i = 0; i<contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return    contas_[i].get_saldo() ;
    }
  }
  return -1;
  //indicador de que nao achou a conta
}

std::string Banco::obterExtrato(int numConta)const
{
  for (size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_extrato();
    }
  }
  return "Conta inexistente";
}

std::string Banco::obterExtrato(int numConta, Data dInicial)const
{
  for (size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_extrato(dInicial);
    }
  }
  return "Conta inexistente";
}

std::string Banco::obterExtrato(int numConta, Data dInicial, Data dFinal)const
{
  for (size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_extrato(dInicial, dFinal);
    }
  }
  return "Conta inexistente";
}

std::vector<Cliente> Banco::obterListaClientes()const
{
  return clientes_;
}

std::vector<Conta> Banco::obterListaContas()const
{
  return contas_;
}



void Banco::gravarDados()
{
  std::ofstream clientes;
  clientes.open("clientes.txt", std::ofstream::out | std::ofstream::trunc);
  std::ofstream contas;
  contas.open("contas.txt", std::ofstream::out | std::ofstream::trunc);

  if(clientes.is_open())
  {
    for(size_t i = 0; i < clientes_.size(); i++)
    {
      clientes << clientes_[i].get_ficha() + "\n";
    }
  }

  clientes.close();

  if (contas.is_open())
  {
    for(size_t i = 0; i < contas_.size(); i++)
    {
      contas << contas_[i].get_ficha_conta() + "\n";
    }
  }
  contas.close();


}

void Banco::lerDados()
{
  std::string nome;
  std::string cpf;
  std::string endereco;
  std::string fone;

  std::string numeroconta;
  std::string saldo;


  std::string data;
  std::string descricao;
  std::string valor;
  std::string dc;
  std::vector<Movimentacao> movs;

  std::string linha;

  std::ifstream clientes("clientes.txt");
  if(clientes.is_open())
  {
    while(getline(clientes,linha))
    {
      std::istringstream slinha(linha);
      getline(slinha, nome, '|');
      getline(slinha, cpf, '|');
      getline(slinha, endereco, '|');
      getline(slinha, fone, '|');
      Cliente clienteCarregado(nome, cpf, endereco, fone);
      this->inserirCliente(clienteCarregado);
    }
  }
  clientes.close();
  std::ifstream contas("contas.txt");

  if (contas.is_open())
  {
    while(getline(contas,linha))
    {
  //    cout<<linha<<endl;
      std::istringstream slinha(linha);
      getline(slinha, numeroconta, '|');
      getline(slinha, saldo, '|');
      getline(slinha, cpf, '|');
      while(slinha)
      {
        getline(slinha, data, '|');
        if (data.empty()) break;
        Data d(data);
        getline(slinha, descricao, '|');
        getline(slinha, valor, '|');
        double dvalor = stod(valor);
        getline(slinha, dc, '|');

        Movimentacao movCarregada(d,descricao,dc[0],dvalor);
        movs.push_back(movCarregada);
      }
      for (size_t i = 0; i < clientes_.size() && !clientes_.empty(); i++)
      {
        if (clientes_[i].getcpf_cnpj() == cpf)
        {
          this->criarConta(clientes_[i]);

        }

      }



    }
    for(size_t j = 0; j < contas_.size() && !contas_.empty(); j++)
    {
      if(contas_[j].get_cliente().getcpf_cnpj() == cpf)
      {
        for (size_t k = 0; k < movs.size() - 1; k++)
        {
          contas_[j].inserirMovimentacao(movs[k]);
        }
      }
    }
    contas.close();
  }
}




std::string Banco::get_dados_conta(int numConta)
{
  for (size_t i = 0; i < contas_.size(); i++)
  {
    if (contas_[i].get_num_conta() == numConta)
    {
      return contas_[i].get_ficha_conta();
    }
  }
  return "conta nao existe";
}

std::string Banco::get_dados_cliente(std::string cpf_cnpj)const
{
  for (size_t i = 0; i < clientes_.size(); i++)
  {
    if (clientes_[i].getcpf_cnpj() == cpf_cnpj)
    {
      return clientes_[i].get_ficha();
    }
  }
  return "cliente nao existe";
}
