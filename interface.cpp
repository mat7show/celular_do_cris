
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include "syscelular.h"
using namespace std;
using namespace tp2;


Interface::Interface(string nome,vector<Cliente> clientes,vector<Celular*> celulares):Operadora(nome,clientes,celulares)
{

}

int Interface::menu()
{
  int menu=1;
  while (menu) {

	for(size_t i = 0; i<erros_global.size(); i++)
	{
		cout << erros_global[i] << endl;
	}
	  cout << endl << endl
		  << "      {{{{{{{{{{}}}}}}}}}}" << endl
		  << "   {{{{{{{{   MENU   }}}}}}}}" << endl
		  << "      {{{{{{{{{{}}}}}}}}}}" << endl;


	  cout << "1.)Cadastrar cliente " << endl
		  << " 2.)Cadastrar celular e plano " << endl
		  << " 3.)Excluir celular " << endl
		  << " 4.)Adicionar creditos (Pre pago) " << endl
		  << " 5.)Registrar ligacao " << endl
		  << " 6.)Ver valor da conta (Pos pago) " << endl
		  << " 7.)Listar Creditos e validade (Pre pago) " << endl
		  << " 8.)Ver extrato de ligacoes " << endl
		  << "9.)Listar os clientes " << endl
		  << "10.)Listar os planos " << endl
		  << "11.)Listar os celulares " << endl
		  << "12.)Listar os vencimentos " << endl
		  << "0.)Sair " << endl;
	  cin >> menu;
	  switch (menu)
	  {
	  case(1):
		  cout << endl << "{{{{Cadastrar cliente}}}}" << endl;
		  this->novocliente();
		  break;


	  case(2):
		  cout << endl << "{{{{Cadastrar celular e plano}}}}" << endl;
		  this->novoplano();
		  break;

	  case(3):
		  cout << endl << "{{{{Excluir celular}}}}" << endl;
		  this->excluirc();
		  break;

	  case(4):
		  cout << endl << "{{{{Adicionar creditos (Pre pago)}}}}" << endl;
		  this->addcreditos();
		  break;

	  case(5):
		  cout << endl << "{{{{Registrar ligacao}}}}" << endl;
		  this->regliga();
		  break;

	  case(6):
		  cout << endl << "{{{{Ver valor da conta(pos pago)}}}}" << endl;
		  this->verconta();
		  break;

	  case(7):
		  cout << endl << "{{{{Listar Creditos e validade (Pre pago)}}}}" << endl;
		  this->listacredval();
		  break;

	  case(8):
		  cout << endl << "{{{{Ver extrato de ligacoes}}}}" << endl;
		  this->extratoliga();
		  break;

	  case(9):
		  cout << endl << "{{{{Listar os clientes}}}}" << endl;
		  this->listaclientes();
		  break;

	  case(10):
		  cout << endl << "{{{{Listar os planos}}}}" << endl;
		  this->listaplanos();
		  break;

	  case(11):
		  cout << endl << "{{{{Listar os celulares}}}}" << endl;
		  this->listacelulares();
		  break;

	  case(12):
		  cout << endl << "{{{{Listar os vencimentos}}}}" << endl;
		  this->listavencidos();
		  break;

	  case(0):
		  cout << endl << "{{{{Adeus}}}}" << endl;
		  break;
	  default:
		  cout << "Comando invalido" << endl;
	  }
  }
return menu;
}

void Interface::novocliente()
{

  string cpf_cnpj;
  string nome;
  string endereco;

  cout<<"Digite o cpf ou cnpj do cliente"<<endl;
  getline(cin,cpf_cnpj);
  getline(cin,cpf_cnpj);
  cout<<"Digite o nome do cliente"<<endl;
  getline(cin,nome);
  //getline(cin,nome);

  cout<<"Digite o endereco do cliente"<<endl;
  getline(cin,endereco);
  //getline(cin,endereco);

  Cliente a(nome, cpf_cnpj, endereco);

  this->inserirCliente(a);
  //try
  cout<<"Cliente inserido"<<endl;
  }


  void Interface::novoplano(){
  std::vector<Cliente> temp;
  Cliente clientetemp;
  string cpf_cnpj;
  int opt;
  bool plan;
  temp = this->obterListaClientes();

  cout<<"Digite o cpf ou cnpj do cliente"<<endl;
  getline(cin,cpf_cnpj);
  getline(cin,cpf_cnpj);
  cout<<"Digite 0 para prepago ou 1 para pospago"<<endl;
  cin >> opt;
  if (opt ==0){plan = false;}
  if (opt ==1){plan = true;}
  if(opt == 0 || opt ==1)
  {

  	for(size_t i=0; i<temp.size(); i++)
  	{
  		if (temp[i].getcpf_cnpj() == cpf_cnpj)
  		{
        this->criarCelular(temp[i],plan);
      }
    }
}
}
void Interface::excluirc()
{
  string numero;
  vector<Celular*> temp;
  temp = this->obterListaCelulares();

cout <<endl<< "Insira o numero do celular"<<endl;
getline(cin,numero);
getline(cin,numero);
this->excluirCelular(numero);
}

void Interface::addcreditos()
{
  string numero;
  double credito;

cout <<endl<< "Insira o numero do celular"<<endl;
getline(cin,numero);
getline(cin,numero);
cout <<endl<< "Insira a quantidade de creditos"<<endl;
cin>>credito;
this->creditar(numero,credito);
}

void Interface::regliga()
{
  int dia, mes, ano,duracao;
  string numero;
  vector<Celular*> temp;
  temp = this->obterListaCelulares();

  cout <<endl<< "Insira o numero do celular"<<endl;
  getline(cin,numero);
  getline(cin,numero);
  cout << "Insira o dia da ligacao"<<endl;
  cin>>dia;
  cout << "Insira o mes da ligacao"<<endl;
  cin>>mes;
  cout << "Insira o ano da ligacao"<<endl;
  cin>>ano;
  DataDMA datalig(dia,mes,ano);
  cout <<endl<< "Insira a duracao em minutos da ligacao"<<endl;
  cin>>duracao;
  Hora horal;

  for (size_t i = 0; i<temp.size(); i++)
  {
    if (temp[i]->getNumero() == numero)
    {
      this->registrar_ligacao(temp[i], datalig, duracao, horal);
      i=temp.size();
    }
  }

}

void Interface::verconta()
{
  string numero;
  cout <<endl<< "Insira o numero do celular"<<endl;
  getline(cin,numero);
  getline(cin,numero);
  this->valorconta(numero);

}


void Interface::listacredval(){
  string numero;
  cout <<endl<< "Insira o numero do celular"<<endl;
  getline(cin,numero);
  getline(cin,numero);
  vector<Celular*> temp;
  temp = this->obterListaCelulares();
    for (size_t i = 0; i<temp.size(); i++)
    {
      if (temp[i]->getNumero() == numero)
      {
      double a =  temp[i]->get_credfat();
      DataDMA b = temp[i]->get_vencimento();

      int dia = b.get_dia();
      int mes = b.get_mes();
      int ano = b. get_ano();

      cout<< "Creditos : "<<a<<endl;
      cout<< "Validade: "<<dia<<"/"<<mes<<"/"<<ano;


      }
    }


}


void Interface::extratoliga()
{
  string numero;
  int dinicial,minicial,ainicial,dfinal,mfinal,afinal;
  vector<Ligacao> temp;

cout <<endl<< "Insira o numero do celular a se avaliar o extrato"<<endl;
getline(cin,numero);
getline(cin,numero);

cout << "Insira o dia inicial da consulta"<<endl;
cin>>dinicial;
cout << "Insira o mes inicial da consulta"<<endl;
cin>>minicial;
cout << "Insira o ano inicial da consulta"<<endl;
cin>>ainicial;
DataDMA dini(dinicial,minicial,ainicial);

cout <<endl<< "Insira o dia final da consulta"<<endl;
cin>>dfinal;
cout << "Insira o mes final da consulta"<<endl;
cin>>mfinal;
cout << "Insira o ano final da consulta"<<endl;
cin>>afinal;

DataDMA dfim(dfinal,mfinal,afinal);

temp = this->obterExtrato(numero,dini,dfim);
}


void Interface::listaclientes()const{
std::vector<Cliente> temp;
Cliente clientetemp;
temp = this->obterListaClientes();

for(std::vector<Cliente>::const_iterator i = temp.begin(); i != temp.end(); ++i)
{
clientetemp =*i;
this->printacliente(clientetemp);
}
}



void Interface::listacelulares()const{
std::vector<Celular*> temp;
//Celular* celulartemp = new Celular;
temp = this->obterListaCelulares();

for(std::vector<Celular*>::const_iterator i = temp.begin(); i != temp.end(); ++i)
{
//celulartemp =*i;
//this->printacelular(*celulartemp);
	this->printacelular(**i);
}
}

void Interface::listaplanos()const{
std::vector<Celular*> temp;
Celular* celulartemp;
temp = this->obterListaCelulares();

for(std::vector<Celular*>::const_iterator i = temp.begin(); i != temp.end(); ++i)
  {
    celulartemp =*i;
    this->printaplano(celulartemp);
  }
}



void Interface::listavencidos()const{
std::vector<Celular*> temp;
Celular* celulartemp;
temp = this->listar_vencidos();

for(std::vector<Celular*>::const_iterator i = temp.begin(); i != temp.end(); ++i)
  {
    celulartemp =*i;
    this->printaplano(celulartemp);
  }
}



void Interface::printacliente(const Cliente &clientet)const
{
  cout<<endl<<endl<<"Nome: "<< clientet.getnomeCliente() <<endl;
  cout<<"CPF/CNPJ: "<< clientet.getcpf_cnpj() <<endl;
  cout<<"Endereço: "<< clientet.getendereco() <<endl;
}

void Interface::printacelular(const Celular &celular)const{
  Cliente c = celular.getDono();
  cout<<endl<<endl<<"Numero: "<< celular.getNumero();
  cout<<endl<<endl<<"Dono: ";
  this->printacliente(c);
}

void Interface::printaplano( Celular* celular)const{
  this->printacelular(*celular);
  string plano = celular->get_plano();
  if (plano =="Pos-pago")
  {
    double a =  celular->get_credfat();
    DataDMA b = celular->get_vencimento();

    int dia = b.get_dia();
    int mes = b.get_mes();
    int ano = b. get_ano();

    cout<< "Fatura : "<<a<<endl;
    cout<< "Vencimento: "<<dia<<"/"<<mes<<"/"<<ano;
  }

  if (plano =="Pre-pago")
  {
    double a =  celular->get_credfat();
    DataDMA b = celular->get_vencimento();

    int dia = b.get_dia();
    int mes = b.get_mes();
    int ano = b. get_ano();

    cout<< "Creditos : "<<a<<endl;
    cout<< "Validade: "<<dia<<"/"<<mes<<"/"<<ano;
  }
}
