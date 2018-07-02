
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "syscelular.h"
using namespace std;
using namespace tp2;


Operadora::Operadora()
{
  nomeOperadora_ = "JP&MA Telecom";
}

Operadora::Operadora(string nome, vector<Cliente> clientes, vector<Celular*> celulares )
{
  clientes_ = clientes;
  celulares_ = celulares;
  nomeOperadora_ = nome;
}


void Operadora::inserirCliente(const Cliente &C)
{
	if (clientes_.max_size() <= clientes_.size())
	{
		throw ExceptVetorCheio("Vetor de clientes cheio");
	}
	else
	{
		try
		{
			clientes_.push_back(C);
		}
		catch (const ExceptOutras &e)
		{
			erros_global.push_back(e.what());
		}
	}
}

void Operadora::criarCelular( const Cliente &C, bool plano)
{
	if (celulares_.max_size() <= celulares_.size()) throw ExceptVetorCheio("Vetor de celulares cheio");
	vector<Ligacao> ent;
	char buff[20];
	int prox_num;

	try
	{
		prox_num = Celular::get_prox_num();
		_itoa_s(prox_num, buff, 10);
		string numero_s(buff);

		DataDMA h;
		h = h + 30;

		if (plano)
		{
			celulares_.push_back(new Pospago(numero_s, C, ent, h,0));
		}
		else
		{
			celulares_.push_back(new Prepago(numero_s, C, ent, 0, h));
		}

		Celular::incr_prox_num();
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}
}






//eu ia usar os iteradores elegantes das listas, mas dado nosso
// tempo (in)disponivel achei melhor usar vetor msm

void Operadora::excluirCliente(std::string cpf_cnpj)
{
	bool flag = false;
	try {
		for (size_t i = 0; i < clientes_.size(); i++)
		{
			if (clientes_[i].getcpf_cnpj() == cpf_cnpj)
			{
				flag = true;
				for (size_t j = 0; j < celulares_.size(); j++)
				{
					if (celulares_[j]->getDono().getcpf_cnpj() == cpf_cnpj)
					{
						throw ExceptOpIleg("Cliente tem celular e nao pode ser removido");
						//joga excess�o do cliente ter celular
					}
				}

				//sobrescrevo o alvo com o ultimo maluco e removo a duplicata no ultimo.
				clientes_[i] = clientes_[clientes_.size() - 1];
				clientes_.pop_back();
			}

		}
		if (!flag)  throw ExceptOpIleg("Cliente inexistente");
	}

	catch (ExceptOutras e)
	{
		erros_global.push_back(e.what());
	}
}

void Operadora::excluirCelular(string numero)
{
	bool flag = false;
	try
	{

		for (size_t i = 0; i < celulares_.size(); i++)
		{
			if (celulares_[i]->getNumero() == numero)
			{
				flag = true;
				delete celulares_[i];
				celulares_[i] = celulares_[celulares_.size() - 1];

				celulares_.pop_back();
				break;
			}
		}


		if(!flag)  throw ExceptOpIleg("Numero inexistente");
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}
}

void Operadora::creditar(string numero, double valor)
{
try
	{
		for (size_t i = 0; i < celulares_.size(); i++)
		{
			if (celulares_[i]->getNumero() == numero)
			{
        if(celulares_[i]->get_plano()=="Pos-pago"){throw ExceptOpIleg("Plano incorreto");}


				DataDMA v = celulares_[i]->get_vencimento() + 180;
				double a = celulares_[i]->get_credfat() + valor;
				celulares_[i]->set_credfat(a);
				celulares_[i]->set_vencimento(v);
			}
		}
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}
}

double Operadora::valorconta(string numero)
{
	try
	{
		for (size_t i = 0; i < celulares_.size(); i++)
		{
			if (celulares_[i]->getNumero() == numero)
			{
if(celulares_[i]->get_plano()=="Pre-pago"){throw ExceptOpIleg ("Plano incorreto");}
				return celulares_[i]->get_credfat();
			}
		}

		//se chega aqui eh pq nao tem a conta
		throw ExceptOpIleg("Numero de celular inexistente");
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}
}

vector<Ligacao> Operadora::obterExtrato(string numConta)const
{
	vector<Ligacao> chamadas_user;
	bool flag = false;
	try
	{
		for (size_t i = 0; i < celulares_.size(); i++)
		{
			if (celulares_[i]->getNumero() == numConta)
			{
				flag = true;
				chamadas_user = celulares_[i]->getlistaChamadas();
				break;
			}
		}
		if (!flag)  throw ExceptOpIleg("Numero de celular inexistente");
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}
	return chamadas_user;
}

vector<Ligacao> Operadora::obterExtrato(string numConta, DataDMA dInicial)const
{
	vector<Ligacao> chamadas_user;
	vector<Ligacao> chamadas_ret;
	bool flag = false;

	try {

		for (size_t i = 0; i < celulares_.size(); i++)
		{
			if (celulares_[i]->getNumero() == numConta)
			{
				flag = true;
				chamadas_user = celulares_[i]->getlistaChamadas();
				break;
			}
		}
		if (!flag)  throw ExceptOpIleg("Numero de celular inexistente");


		for (size_t i = 0; i < chamadas_user.size(); i++)
		{
			if (chamadas_user[i].get_data_ligacao() > dInicial)
			{
				chamadas_ret.push_back(chamadas_user[i]);
			}
		}
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}
	return chamadas_ret;
}

std::vector<Ligacao> Operadora::obterExtrato(string numConta, DataDMA dInicial, DataDMA dFinal)const
{
	vector<Ligacao> chamadas_user;
	vector<Ligacao> chamadas_ret;
	bool flag = false;

	try
	{

		for (size_t i = 0; i < celulares_.size(); i++)
		{
			if (celulares_[i]->getNumero() == numConta)
			{
				flag = true;
				chamadas_user = celulares_[i]->getlistaChamadas();
				break;
			}
		}
		if (!flag) throw ExceptOpIleg("Numero de celular inexistente");//throw excessao de conta inexistente


		for (size_t i = 0; i < chamadas_user.size(); i++)
		{
			if (chamadas_user[i].get_data_ligacao() > dInicial && chamadas_user[i].get_data_ligacao() < dFinal)
			{
				chamadas_ret.push_back(chamadas_user[i]);
			}
		}
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}
	return chamadas_ret;

}

vector<Cliente> Operadora::obterListaClientes()const
{
  return clientes_;
}

vector<Celular*> Operadora::obterListaCelulares()const
{
  return celulares_;
}


void Operadora::registrar_ligacao(Celular* C, DataDMA dataLig, int duracao, Hora horalig)
{
	if (!dataLig.valida()) throw ExceptData("Data invalida");

	try
	{
		bool flag = false;
		Ligacao L(dataLig, duracao, horalig);
		for (size_t i = 0; i < celulares_.size(); i++)
		{
			if (C->getNumero() == celulares_[i]->getNumero())
			{
				flag = true;
				C->realizar_chamada(dataLig, duracao, horalig);
			}
		}
		if (!flag) throw ExceptOpIleg("Numero de celular inexistente");  //excessao de nao tem esse numero
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}
}


vector<Celular*> Operadora::listar_vencidos()const
{
	vector<Celular*> ret;
	DataDMA Hoje;
	if (!Hoje.valida()) throw ExceptData("Data invalida");

	try
	{
		for (size_t i = 0; i < celulares_.size(); i++)
		{

			if (celulares_[i]->get_vencimento() <= Hoje)
			{
				ret.push_back(celulares_[i]);
			}
		}
	}
	catch (const ExceptOutras &e)
	{
		erros_global.push_back(e.what());
	}

	return ret;
}


void Operadora::inicializa_numero(int n)
{
	Celular::set_prox_num(n);
}