
#ifndef SYSCELULAR_H
#define SYSCELULAR_H

#include <string>
#include <list>

//using namespace std;


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

	class Chamada
	{
	private:


	public:

	};


	class Cliente
	{
	private:
		std::string nomeCliente;
		std::string cpf_cnpj_;
		std::string endereco;



	public:
		Cliente(std::string name, std::string id, std::string add);
		Cliente(const Cliente &a);
		Cliente();

		std::string getnomeCliente()const;
		std::string getcpf_cnpj()const;
		std::string getendereco()const;

		void setnomeCliente(std::string name);
		void setcpf_cnpj(std::string id);
		void setendereco(std::string add);

	};

	class Celular
	{
	private:
		std::string numero_;
		Cliente dono_;
		std::list<Chamada> listaChamadas_;



	public:
		Celular(std::string numero, const Cliente &dono, std::list<Chamada> listaChamadas);
		Celular(const Celular &a);

		std::string getNumero ()const;
		Cliente getDono ()const;
		std::list<Chamada> getlistaChamadas ()const;

		void setNumero(std::string numero);
		void setDono(const Cliente &dono);
		void setlistaChamadas(std::list<Chamada> listaChamadas);

		virtual bool get_plano();

	};


	class Prepago : public Celular
	{
	private:
		double creditos_;
		DataDMA validade_;
		bool plano;
	public:
		Prepago (std::string numero,const Cliente &dono, std::list<Chamada> listaChamadas, double creditos,DataDMA validade );
		double get_creditos ()const;
		DataDMA get_validade ()const;
		void set_creditos(double creditos);
		void set_creditos(DataDMA vencimento);
		bool get_plano();

	};

	class Pospago : public Celular
	{
	private:
		DataDMA vencimento_;
		bool plano;
	public:
		Pospago (std::string numero,const Cliente &dono, std::list<Chamada> listaChamadas, double creditos,const DataDMA &vencimento);
		DataDMA get_vencimento ()const;
		void set_vencimento(const DataDMA &vencimento);
		bool get_plano();

	};



	class Operadora
	{
	private:
		std::list<Cliente> clientes_;
		std::list<Celular> celulares_;
		std::string nomeOperadora_;

	public:
		Operadora();
		Operadora(std::string nome, std::list<Cliente> clientes, std::list<Celular> contas);

		void inserirCliente(const Cliente &C);
		void criarCelular(const Cliente &C);
		void excluirCliente(std::string cpf_cnpj);
		void excluirConta(int numConta);
		std::string obterExtrato(int numConta)const;
		std::string obterExtrato(int numConta, DataDMA dInicial)const;
		std::string obterExtrato(int numConta, DataDMA dInicial, DataDMA dFinal)const;
		std::list<Cliente> obterListaClientes()const;
		std::list<Celular> obterListaCelulares()const;

	};

	class Interface : public Operadora{
	private:

	public:

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
