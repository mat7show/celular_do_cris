#pragma once

#ifndef SISTEMA_DE_CELULAR
#define SISTEMA_DE_CELULAR

#include <string>
#include <list>

using namespace std;

namespace celular {

	class Cliente
	{
	private:
		string nomeCliente;
		string cpf_cnpj_;
		string endereco;
		string fone;


	public:
		Cliente(string name, string id, string add, string pho);
		Cliente(const Cliente &a);
		Cliente();

		string getnomeCliente()const;
		string getcpf_cnpj()const;
		string getendereco()const;
		string getfone()const;
		string get_ficha()const;
		void setnomeCliente(std::string name);
		void setcpf_cnpj(std::string id);
		void setendereco(std::string add);
		void setfone(std::string pho);
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


	class Data
	{
	private:

	public:

		

		int get_dia();
		int get_mes();
		int get_ano();



	};


}












#endif

