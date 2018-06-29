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



	public:
		Cliente(string name, string id, string add, string pho);
		Cliente(const Cliente &a);
		Cliente();

		string getnomeCliente()const;
		string getcpf_cnpj()const;
		string getendereco()const;

		//string get_ficha()const;
		void setnomeCliente(std::string name);
		void setcpf_cnpj(std::string id);
		void setendereco(std::string add);

	};


	class Chamada
	{
	private:


	public:

	};



	class Celular
	{
	private:
		string numero_;
		Cliente dono_;
		list<Chamada> listaChamadas_;
		bool plano_;       //true representa assinatura p�s-pago. false representa cart�o pr�-pago

	public:
		Celular(string numero, const Cliente &dono, list<Chamada> listaChamadas, bool plano);
		Celular(const Celular &a);
		string getNumero ()const;
		Cliente getDono ()const;
		list<Chamada> getlistaChamadas ()const;
		bool getPlano()const;
		void setNumero(string numero);
		void setDono(const Cliente &dono);
		void setlistaChamadas(list<Chamada> listaChamadas);
		void setPlano(bool plano);
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
