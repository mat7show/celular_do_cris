
#ifndef SYSCELULAR_H
#define SYSCELULAR_H

#include <string>
#include <vector>

//using namespace std;


namespace tp2 {

	class ExceptCreditoIns

	{
	private:
		std::string erro_;

	public:
		ExceptCreditoIns(std::string e);
		std::string what();
	};

	class ExceptVetorCheio
	{
	private:
		std::string erro_;
	public:
		ExceptVetorCheio(std::string e);
		std::string what();

	};

	class ExceptContaInex
	{
	private:
		std::string erro_;

	public:
		ExceptContaInex(std::string e);
		std::string what();

	};

	class ExceptData
	{
	private:
		std::string erro_;

	public:
		ExceptData(std::string e);
		std::string what();

	};

	class ExceptOutras : public std::runtime_error //ja vem com funcao what();
	{
	private:
		std::string erro_;
	public:
		ExceptOutras(std::string what);

	};





	class Hora
	{
	private:
		std::string timestamp_;

	public:
		Hora();
		std::string get_timestamp();

	};

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

		long n_dias_em_data();
		static DataDMA data_de_n_dias(int dias);

	public:
		DataDMA();
		DataDMA(int dia, int mes, int ano);
		DataDMA(long dias_passados_desde_1970);
		DataDMA(DataDMA const &d);


		int get_dia() const;
		int get_mes() const;
		int get_ano() const;
		std::string get_data_formatada() const;
		bool valida();

		DataDMA operator+(DataDMA d);
		DataDMA operator+(long d);
		DataDMA operator-(DataDMA d);
		DataDMA operator=(DataDMA d);
		bool operator==(DataDMA d);
		bool operator<(DataDMA d);
		bool operator<=(DataDMA d);
		bool operator>(DataDMA d);
		bool operator>=(DataDMA d);

	};


	class Ligacao
	{
	private:
		DataDMA data_ligacao_;
		Hora hora_ligacao_;
		int duracao_;

	public:
		Ligacao(DataDMA dataLig, int duracao, Hora horalig);
		Ligacao(const Ligacao &M);


		DataDMA get_data_ligacao()const;
		Hora get_hora_ligacao()const;
		int get_duracao()const;
		std::string get_info_ligacao()const;
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
		std::vector<Ligacao> listaChamadas_;


	public:



		Celular(std::string numero, const Cliente &dono, std::vector<Ligacao> listaChamadas);
		Celular(const Celular &a);

		std::string getNumero()const;
		Cliente getDono()const;
		std::vector<Ligacao> getlistaChamadas()const;

		void setNumero(std::string numero);
		void setDono(const Cliente &dono);
		void setlistaChamadas(std::vector<Ligacao> listaChamadas);


		virtual std::string get_plano()=0;
		virtual	DataDMA get_vencimento()const = 0;
		virtual	void set_vencimento(const DataDMA &vencimento) = 0;
		virtual	void set_credfat(double fatura) = 0;
		virtual	double get_credfat()const = 0;
		virtual void realizar_chamada(DataDMA dataLig, int duracao, Hora horalig) = 0;

	};


	class Prepago : public Celular
	{
	private:
		double creditos_;
		DataDMA validade_;
		static const int custo_p_min = 3;



	public:
		Prepago(std::string numero, const Cliente &dono, std::vector<Ligacao> listaChamadas, double creditos, const DataDMA &validade);
		double get_creditos()const;
		DataDMA get_validade()const;
		void set_creditos(double creditos);
		void set_validade(const DataDMA &validade);
		static int get_custo_p_min();




		DataDMA get_vencimento()const;
		void set_vencimento(const DataDMA &vencimento);
		std::string get_plano();
		void realizar_chamada(DataDMA dataLig, int duracao, Hora horalig);
		double get_credfat()const;
		void set_credfat(double fatura);




	};

	class Pospago : public Celular
	{
	private:
		DataDMA vencimento_;
		double fatura_;

	public:
		Pospago(std::string numero, const Cliente &dono, std::vector<Ligacao> listaChamadas, const DataDMA &vencimento);
		DataDMA get_vencimento()const;
		void set_vencimento(const DataDMA &vencimento);
		double get_fatura()const;
		void set_fatura(double fatura);



		void realizar_chamada(DataDMA dataLig, int duracao, Hora horalig);
		double get_credfat()const;
		std::string get_plano();
		void set_credfat(double fatura);



	};



	class Operadora
	{
	private:
		std::vector<Cliente> clientes_;
		std::vector<Celular*> celulares_;
		std::string nomeOperadora_;

	public:
		Operadora();
		Operadora(std::string nome, std::vector<Cliente> clientes, std::vector<Celular*> contas);

		void inserirCliente(const Cliente &C);
		void criarCelular(const Cliente &C, bool plano);
		void excluirCliente(std::string cpf_cnpj);
		void excluirCelular(std::string numConta);
		void creditar(std::string numero, double valor);
		double valorconta(std::string numero);
		std::vector<Ligacao> obterExtrato(std::string numConta)const;
		std::vector<Ligacao> obterExtrato(std::string numConta, DataDMA dInicial)const;
		std::vector<Ligacao> obterExtrato(std::string numConta, DataDMA dInicial, DataDMA dFinal)const;
		std::vector<Cliente> obterListaClientes()const;
		std::vector<Celular*> obterListaCelulares()const;

		void registrar_ligacao(Celular* C, DataDMA dataLig, int duracao, Hora horalig);
		std::vector<Celular*> listar_vencidos()const;




	};

	class Interface : public Operadora {
	public:
		Interface(std::string nome, std::vector<Cliente> clientes, std::vector<Celular*> celulares);
		int menu();
		void novocliente();
		void novoplano();
		void excluirc();
		void addcreditos();
		void regliga();
		void verconta();
		void listacredval();
		void extratoliga();
		void printacliente(const Cliente &clientet)const;
		void listaclientes()const;
		void printacelular(const Celular &celular)const;
		void listacelulares()const;
		void listaplanos()const;
		void printaplano(Celular* celular)const;
		void listavencidos()const;


	};
}











#endif
