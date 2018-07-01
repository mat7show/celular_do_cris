
#include <iostream>
#include <string>
#include <vector>
#include "syscelular.h"
using namespace std;
using namespace operadora;

Interface::Interface(){
}

Interface::Interface(string nome,vector<Cliente> clientes,vector<Celular> contas):Banco(nome,clientes,contas){

}

int Interface::menu(){
  int menu;

	cout << endl << endl
		 << "      {{{{{{{{{{}}}}}}}}}" << endl
		 << "   {{{{{{{{   MENU   }}}}}}}" << endl
		 << "      {{{{{{{{{{}}}}}}}}}" << endl;


		cout <<"1.)Cadastrar cliente " << endl
       << " 2.)Cadastrar plano"<<endl
       << " 3.)Habilitar celular " << endl
       << " 4.)Excluir celular " << endl
       << " 5.)Adicionar creditos (Pre pago) " << endl
       << " 6.)Registrar ligacao " << endl
       << " 7.)Ver valor da conta (Pos pago) " << endl
       << " 8.)Listar Creditos e validade (Pre pago) " << endl
       << "9.)Ver extrato de ligacoes " << endl
       << "10.)Listar os clientes " << endl
       << "11.)Listar os planos " << endl
      << "12.)Listar os celulares " << endl
      << "13.)Listar os vencimentos " << endl
       << "0.)Sair " << endl;
			cin >> menu;
switch (menu)
{
case(1):
cout<<endl<<"{{{{Cadastrar cliente}}}}"<<endl;
this->novocliente();
break;


case(2):
cout<<endl<<"{{{{Cadastrar plano}}}}"<<endl;
this->novoplano();
break;

case(3):
cout<<endl<<"{{{{Habilitar celular}}}}"<<endl;
this->habcelular();
break;

case(4):
cout<<endl<<"{{{{Excluir celular}}}}"<<endl;
this->excluircelular();
break;

case(5):
cout<<endl<<"{{{{Adicionar creditos (Pre pago)}}}}"<<endl;
this->addcreditos();
break;

case(6):
cout<<endl<<"{{{{Registrar ligacao}}}}"<<endl;
this->regliga();
break;

case(7):
cout<<endl<<"{{{{Ver valor da conta(pos pago)}}}}"<<endl;
this->verconta();
break;

case(8):
cout<<endl<<"{{{{Listar Creditos e validade (Pre pago)}}}}"<<endl;
this->listacredval();
break;

case(9):
cout<<endl<<"{{{{Ver extrato de ligacoes}}}}"<<endl;
this->extratoliga();
break;

case(10):
cout<<endl<<"{{{{Listar os clientes}}}}"<<endl;
this->listacliente();
break;

case(11):
cout<<endl<<"{{{{Listar os planos}}}}"<<endl;
this->listaplano();
break;

case(12):
cout<<endl<<"{{{{Listar os celulares}}}}"<<endl;
this->listacelular();
break;

case(13):
cout<<endl<<"{{{{Listar os vencimentos}}}}"<<endl;
this->listavencimento();
break;

case(0):
cout<<endl<<"{{{{Adeus}}}}"<<endl;
break;
default:
cout<<"Comando invalido"<<endl;
}
return menu;
}

void Interface::novocliente(){

  string cpf_cnpj;
  string nome;
  string endereco;

  cout<<"Digite o cpf ou cnpj do cliente"<<endl;
  getline(cin,cpf_cnpj);
  getline(cin,cpf_cnpj);
  cout<<"Digite o nome do cliente"<<endl;
  getline(cin,nome);
  getline(cin,nome);

  cout<<"Digite o endereco do cliente"<<endl;
  getline(cin,endereco);
  getline(cin,endereco);

  Cliente a(cpf_cnpj,nome, endereco);

  this->inserirCliente(a);
  //try
  cout<<"Cliente inserido"<<endl;
  }


void Interface::novoplano(){
  string numero;
  int opt;
  int dia;
  int mes;
  int ano;
  double credito;
vector<Celular> temp;
temp = this->obterListaCelulares();
bool existe = false;
cout <<endl<< "Insira o numero de celular"<<endl;
getline(cin,numero);
getline(cin,numero);
cout <<endl<< "Insira 0 para prepago ou 1 para pospago"<<endl;
cin>>opt;

if (opt = 1)
{
  cout << "Insira o dia do vencimento"<<endl;
  cin>>dia;
  cout << "Insira o mes do vencimento"<<endl;
  cin>>mes;
  cout << "Insira o ano do vencimento"<<endl;
  cin>>ano;
  DataDMA data(dia,mes,ano);

for (size_t i = 0; i<temp.size(); i++)
{
  if (temp[i].getNumero() == numero)
  {
    existe = true;
    this->criarpos(temp[i],data);
    i=temp.size();
  }
}
}
if (opt = 0)
{
  cout << "Insira o dia da validade"<<endl;
  cin>>dia;
  cout << "Insira o mes da validade"<<endl;
  cin>>mes;
  cout << "Insira o ano da validade"<<endl;
  cin>>ano;
  DataDMA data(dia,mes,ano);
cout <<endl<< "Insira a quantidade de creditos"<<endl;
cin>> credito;
for (size_t i = 0; i<temp.size(); i++)
{
  if (temp[i].getNumero() == numero)
  {
    existe = true;
    this->criarpre(temp[i],data,credito);
    i=temp.size();
  }
}

}


}

void Interface::habcelular(){
  string numero;

cout <<endl<< "Insira o numero do celular"<<endl;
getline(cin,numero);
getline(cin,numero);
for (size_t i = 0; i<temp.size(); i++)
{
  if (temp[i].getNumero() == numero)
  {
    existe = true;
    this->Habilitar(temp[i]);
    i=temp.size();
  }
}
}

void Interface::excluircelular(){
  string numero;

cout <<endl<< "Insira o numero do celular"<<endl;
getline(cin,numero);
getline(cin,numero);
for (size_t i = 0; i<temp.size(); i++)
{
  if (temp[i].getNumero() == numero)
  {
    existe = true;
    this->excluir(temp[i]);
    i=temp.size();
  }
}
}

void Interface::addcreditos(){
  string numero;
  double credito;

cout <<endl<< "Insira o numero do celular"<<endl;
getline(cin,numero);
getline(cin,numero);
cout <<endl<< "Insira a quantidade de creditos"<<endl;
cin>>credito;
this->creditar(numero,credito);
}

void Interface::regliga(){

}

void Interface::verconta(){
  cout <<endl<< "Insira o numero do celular"<<endl;
  getline(cin,numero);
  getline(cin,numero);
  this->vericonta(numero)

}
void Interface::listacredval(){
  cout <<endl<< "Insira o numero do celular"<<endl;
  getline(cin,numero);
  getline(cin,numero);
  this->vercredval(numero)

}

void Interface::extratoliga(){
  int numero;
  string extrato;
  int dinicial,minicial,ainicial,dfinal,mfinal,afinal;

cout <<endl<< "Insira o numero da conta a se avaliar extrato"<<endl;
cin>>numConta;
cout << "Insira o dia inicial da consulta"<<endl;
cin>>dinicial;
cout << "Insira o mes inicial da consulta"<<endl;
cin>>minicial;
cout << "Insira o ano inicial da consulta"<<endl;
cin>>ainicial;
Data dini(dinicial,minicial,ainicial);
cout <<endl<< "Insira o dia final da consulta"<<endl;
cin>>dfinal;
cout << "Insira o mes final da consulta"<<endl;
cin>>mfinal;
cout << "Insira o ano final da consulta"<<endl;
cin>>afinal;
Data dfim(dfinal,mfinal,afinal);

extrato = this->obterExtrato(numero,dini,dfim);
cout<<extrato<<endl;
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

void Interface::listaplanos()const{
std::vector<Celular> temp;
Celular celulartemp;
temp = this->obterListaPlanos();

for(std::vector<Celular>::const_iterator i = temp.begin(); i != temp.end(); ++i)
{
celulartemp =*i;
this->printaplano(celulartemp);
}
}
void Interface::listacelulares()const{
std::vector<Celular> temp;
Celular celulartemp;
temp = this->obterListaCelulares();

for(std::vector<Celular>::const_iterator i = temp.begin(); i != temp.end(); ++i)
{
celulartemp =*i;
this->printacelular(celulartemp);
}
}

void Interface::listavencimentos()const{
std::vector<Celular> temp;
Celular celulartemp;
temp = this->obterListaPlanos();

for(std::vector<Celular>::const_iterator i = temp.begin(); i != temp.end(); ++i)
{
celulartemp =*i;
this->printaplano(celulartemp);
}
}



void Interface::printacliente(const Cliente &clientet)const{
  cout<<endl<<endl<<"Nome: "<< clientet.getnomeCliente() <<endl;
  cout<<"CPF/CNPJ: "<< clientet.getcpf_cnpj() <<endl;
  cout<<"Endereço: "<< clientet.getendereco() <<endl;
  cout<<"Telefone: "<< clientet.getfone() <<endl;
}

void Interface::printaconta(const Conta &contat)const{
  cout<<endl<<endl<<"Numero da conta: "<< contat.get_num_conta();
}
