#pragma once

#ifndef SISTEMA_DE_CELULAR
#define SISTEMA_DE_CELULAR

#include <string>
#include <list>

using namespace std;


namespace operadora {


	class ExcData
	{
	private:

	public:

	};



	class DataDMA
	{
	private:
		int dia_;
		int mes_;
		int ano_;

		int n_dias_em_data() const;
		static DataDMA data_de_n_dias(int dias);

	public:
		DataDMA();
		DataDMA(int dia, int mes, int ano);
		DataDMA(int dias_passados_desde_1970);
		DataDMA(DataDMA const &d);


		int get_dia() const;
		int get_mes() const;
		int get_ano() const;
		bool valida();

		DataDMA operator+(DataDMA d);
		DataDMA operator+(int d);
		DataDMA operator-(DataDMA d);
		DataDMA operator=(DataDMA d);
		bool operator==(DataDMA d);
		bool operator<(DataDMA d);
		bool operator<=(DataDMA d);
		bool operator>(DataDMA d);
		bool operator>=(DataDMA d);





	};

	class Interface : Operadora
	{
	private:

	public:

	};

	class Operadora
	{
	private: 
		list<Cliente> clientes_;
		list<Celular> celulares_;
		string nomeOperadora_;

	public:
		Operadora();
		Operadora(string nome, list<Cliente> clientes, list<Celular> contas);

		void inserirCliente(const Cliente &C);
		void criarCelular(const Cliente &C);
		void excluirCliente(string cpf_cnpj);
		void excluirConta(int numConta);
		string obterExtrato(int numConta)const;
		string obterExtrato(int numConta, DataDMA dInicial)const;
		string obterExtrato(int numConta, DataDMA dInicial, DataDMA dFinal)const;
		list<Cliente> obterListaClientes()const;
		list<Celular> obterListaCelulares()const;




	};



	class Cliente
	{
	private:
		string nomeCliente;
		string cpf_cnpj_;
		string endereco;



	public:
		Cliente(string name, string id, string add);
		Cliente(const Cliente &a);
		Cliente();

		string getnomeCliente()const;
		string getcpf_cnpj()const;
		string getendereco()const;

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
		

	public:
		Celular(string numero, const Cliente &dono, list<Chamada> listaChamadas, bool plano);
		Celular(const Celular &a);
		string getNumero ()const;
		Cliente getDono ()const;
		list<Chamada> getlistaChamadas ()const;
		
		void setNumero(string numero);
		void setDono(const Cliente &dono);
		void setlistaChamadas(list<Chamada> listaChamadas);
		void setPlano(bool plano);
	};


	class Pospago : Celular
	{
	private:
		double creditos_;
		DataDMA validade_;

	public:
		double get_creditos();
		DataDMA get_validade();

	};

	class Prepago : Celular
	{
	private:
		DataDMA vencimento_;

	public:
		DataDMA get_vencimento();

	};


	class Ligacao
	{
	private:
		DataDMA data_ligacao_;

		//comentei pra compilar enqnto nao implemento HORA
		//Hora hora_ligacao_;
		int duracao_;

	public:
		Ligacao(DataDMA dataLig, int duracao);
		Ligacao(const Ligacao &M);


		DataDMA get_data_ligacao()const;
		//Hora get_hora_ligacao()const;
		int get_duracao()const;
	};

	


}












#endif
