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
  nomeOperadora_ = "JP&MA Chase";
}

Operadora::Operadora(string nome, list<Cliente> clientes, list<Celular> celulares )
{
  clientes_ = clientes;
  celulares_ = celulares;
  nomeOperadora_ = nome;
}

void Operadora::inserirCliente(const Cliente &C)
{
  
}

void Operadora::criarCelular( const Cliente &C)
{
 
}

void Operadora::excluirCliente(std::string cpf_cnpj)
{
  bool tem_celular = false;
 
}

void Operadora::excluirConta(int numConta)
{
  
}



string Operadora::obterExtrato(int numConta)const
{
	return "";
}

string Operadora::obterExtrato(int numConta, DataDMA dInicial)const
{
  
  return "Conta inexistente";
}

std::string Operadora::obterExtrato(int numConta, DataDMA dInicial, DataDMA dFinal)const
{
  
  return "Conta inexistente";
}

list<Cliente> Operadora::obterListaClientes()const
{
  return clientes_;
}

list<Celular> Operadora::obterListaCelulares()const
{
  return celulares_;
}


