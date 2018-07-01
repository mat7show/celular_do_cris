#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "syscelular.h"
using namespace std;
using namespace operadora;


Operadora::Operadora()
{
  nomeOperadora_ = "JP&MA Telecom";
}

Operadora::Operadora(string nome, vector<Cliente> clientes, vector<Celular> celulares )
{
  clientes_ = clientes;
  celulares_ = celulares;
  nomeOperadora_ = nome;
}

void Operadora::inserirCliente(const Cliente &C)
{
	if (clientes_.max_size() <= clientes_.size())
	{
		//joga excess�o de clientes_cheio aqui
	}
	else clientes_.push_back(C);
}

void Operadora::criarCelular( const Cliente &C)
{

}


//eu ia usar os iteradores elegantes das listas, mas dado nosso
// tempo (in)disponivel achei melhor usar vetor msm

void Operadora::excluirCliente(std::string cpf_cnpj)
{
	bool flag = false;
	for(size_t i=0; i<clientes_.size(); i++)
	{
		if (clientes_[i].getcpf_cnpj() == cpf_cnpj)
		{
			flag = true;
			for (size_t j =0; j<celulares_.size();j++)
			{
				if (celulares_[j].getDono().getcpf_cnpj() == cpf_cnpj)
				{
					//joga excess�o do cliente ter celular
				}
			}

			//sobrescrevo o alvo com o ultimo maluco e removo a duplicata no ultimo.
			clientes_[i] = clientes_[clientes_.size() - 1];
			clientes_.pop_back();
		}


	}
	//if (!flag) // joga excessao de cliente inexistente
}

void Operadora::excluirCelular(string numero)
{
	bool flag = false;
	for(size_t i = 0; i<celulares_.size(); i++)
	{
		if(celulares_[i].getNumero() == numero)
		{
		  flag = true;
		  celulares_[i] = celulares_[celulares_.size() - 1];
		  celulares_.pop_back();
		  break;
		}
	}
	//if(!flag) //throw excessao de conta nao existente
}

void Operadora::creditar(string numero, double valor)
{
  //excessão caso o plano não for prepago
  for(size_t i = 0; i<celulares_.size(); i++)
  {
    if(celulares_[i].getNumero() == numero)
    {
      DataDMA v = celulares_[i].get_validade() + 180;
      double a = celulares_[i].get_creditos() + valor;
      celulares_[i].set_creditos(a);
      celulares_[i].set_validade(v);
    }
  }
}

double Operadora::valorconta(string numero)
{
//excessão caso não for pospago
  for(size_t i = 0; i<celulares_.size(); i++)
  {
    if(celulares_[i].getNumero() == numero)
    {
      return celulares_[i].get_fatura();
    }
  }
}

vector<Ligacao> Operadora::obterExtrato(string numConta)const
{
	vector<Ligacao> chamadas_user;
	bool flag = false;

	for (size_t i = 0; i<celulares_.size(); i++)
	{
		if (celulares_[i].getNumero() == numConta)
		{
			flag = true;
			chamadas_user = celulares_[i].getlistaChamadas();
			break;
		}
	}
	if (!flag) //throw excessao de conta inexistente


	return chamadas_user;
}

vector<Ligacao> Operadora::obterExtrato(string numConta, DataDMA dInicial)const
{
	vector<Ligacao> chamadas_user;
	vector<Ligacao> chamadas_ret;
	bool flag = false;

	for (size_t i = 0; i<celulares_.size(); i++)
	{
		if (celulares_[i].getNumero() == numConta)
		{
			flag = true;
			chamadas_user = celulares_[i].getlistaChamadas();
			break;
		}
	}
	//if (!flag) //throw excessao de conta inexistente


	for (size_t i = 0; i < chamadas_user.size(); i++)
	{
		if (chamadas_user[i].get_data_ligacao() > dInicial)
		{
			chamadas_ret.push_back(chamadas_user[i]);
		}
	}

	return chamadas_ret;
}

std::vector<Ligacao> Operadora::obterExtrato(string numConta, DataDMA dInicial, DataDMA dFinal)const
{
	vector<Ligacao> chamadas_user;
	vector<Ligacao> chamadas_ret;
	bool flag = false;

	for (size_t i = 0; i<celulares_.size(); i++)
	{
		if (celulares_[i].getNumero() == numConta)
		{
			flag = true;
			chamadas_user = celulares_[i].getlistaChamadas();
			break;
		}
	}
	//if (!flag) //throw excessao de conta inexistente


		for (size_t i = 0; i < chamadas_user.size(); i++)
		{
			if (chamadas_user[i].get_data_ligacao() > dInicial && chamadas_user[i].get_data_ligacao() < dFinal)
			{
				chamadas_ret.push_back(chamadas_user[i]);
			}
		}

	return chamadas_ret;

}

vector<Cliente> Operadora::obterListaClientes()const
{
  return clientes_;
}

vector<Celular> Operadora::obterListaCelulares()const
{
  return celulares_;
}


void Operadora::registrar_ligacao(Celular C, DataDMA dataLig, int duracao, Hora horalig)
{
	bool flag = false;
	Ligacao L(dataLig, duracao, horalig);
	for(size_t i=0; i < celulares_.size(); i++)
	{
		if(C.getNumero() == celulares_[i].getNumero)
		{
			flag = true;
			C.realizar_chamada(dataLig, duracao, horalig);
		}
	}
	//if (!flag) excessao de nao tem esse numero
}


vector<Celular> Operadora::listar_vencidos()
{
	vector<Celular> ret;

	return ret;
}