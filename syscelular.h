#pragma once

#ifndef SISTEMA_DE_CELULAR
#define SISTEMA_DE_CELULAR

#include <string>
#include <list>

using namespace std;


class Cliente
{
private:
	string nome;
	string cpf_cnpj;
	string endereco;


public:

	string getNome();
	string getCpf_cnpj();
	string getEndereco();
};


class Chamada
{
private:


public:

};



class Celular
{
private:
	string numero;
	Cliente dono;
	list<Chamada> listaChamadas;
	bool assinatura;       //true representa assinatura pós-pago. false representa cartão pré-pago

public:
	string getNumero();
	Cliente getDono();
	list<Chamada> getListaChamadas();
	bool getAssinatura();
};


class Pospago : Celular
{
private:

public:

};

class Prepago : Celular
{
private:

public:


};


















#endif

