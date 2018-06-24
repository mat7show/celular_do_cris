#include <iostream>
#include <string>
#include <vector>
#include "banksys.h"
using namespace std;
using namespace banco;

Interface::Interface(){
}

Interface::Interface(string nome,vector<Cliente> clientes,vector<Conta> contas):Banco(nome,clientes,contas){

}

int Interface::menu(){
  int menu;

	cout << endl << endl
		 << "      {{{{{{{{{{}}}}}}}}}" << endl
		 << "   {{{{{{{{   MENU   }}}}}}}" << endl
		 << "      {{{{{{{{{{}}}}}}}}}" << endl;


		cout <<"1.)Novo cliente " << endl
			 << " 2.)Excluir cliente " << endl
       << " 3.)Nova conta"<<endl
       << " 4.)Excluir conta " << endl
       << " 5.)Realizar deposito " << endl
       << " 6.)Realizar saque " << endl
       << " 7.)Realizar transferencia " << endl
       << " 8.)Cobrar tarifa " << endl
       << " 9.)Cobrar cpmf " << endl
       << "10.)Ver o saldo " << endl
       << "11.)Ver o extrato " << endl
       << "12.)Listar os clientes " << endl
       << "13.)Listar as contas " << endl
       << "0.)Sair " << endl;
			cin >> menu;
switch (menu)
{
case(1):
cout<<endl<<"{{{{Novo cliente}}}}"<<endl;
this->novocliente();
break;

case(2):
cout<<endl<<"{{{{Excluir cliente}}}}"<<endl;
this->excluirclientei();
break;

case(3):
cout<<endl<<"{{{{Nova conta}}}}"<<endl;
this->novaconta();
break;

case(4):
cout<<endl<<"{{{{Excluir conta}}}}"<<endl;
this->excluircontai();
break;

case(5):
cout<<endl<<"{{{{Realizar deposito}}}}"<<endl;
this->depositoi();
break;

case(6):
cout<<endl<<"{{{{Realizar saque}}}}"<<endl;
this->saquei();
break;

case(7):
cout<<endl<<"{{{{Realizar transferencia}}}}"<<endl;
this->transferenciai();
break;

case(8):
cout<<endl<<"{{{{Cobrar tarifa}}}}"<<endl;
this->cobrartarifai();
break;

case(9):
cout<<endl<<"{{{{Cobrar CPMF}}}}"<<endl;
this->cobrarcpmfi();
break;

case(10):
cout<<endl<<"{{{{Ver o saldo}}}}"<<endl;
this->saldoi();
break;

case(11):
cout<<endl<<"{{{{Ver o extrato}}}}"<<endl;
this->extratoi();
break;

case(12):
cout<<endl<<"{{{{Listar clientes}}}}"<<endl;
this->listaclientes();
break;

case(13):
cout<<endl<<"{{{{Listar contas}}}}"<<endl;
this->listacontas();
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

  string name,id,add,pho;

  cout<<endl<<"Digite o nome do cliente "<<endl;
  getline(cin,name);
  getline(cin,name);

  cout<<"Digite o cpf ou cnpj do cliente"<<endl;
  getline(cin,id);
  cout<<"Digite o endereço do cliente"<<endl;
  getline(cin,add);
  cout<<"Digite o telefone do cliente"<<endl;
  getline(cin,pho);
  Cliente novo(name,id,add,pho);
  this->inserirCliente (novo);
  cout<<"Cliente criado"<<endl;
}

void Interface::novaconta(){

  string cpf_cnpj;
  vector<Cliente> temp;
  temp = this->obterListaClientes();
  bool existe = false;
  cout<<"Digite o cpf ou cnpj do cliente"<<endl;
  getline(cin,cpf_cnpj);
  getline(cin,cpf_cnpj);
  for (size_t i = 0; i<temp.size(); i++)
  {
    if (temp[i].getcpf_cnpj() == cpf_cnpj)
    {
      existe = true;
      this->criarConta(temp[i]);
      i=temp.size();
    }
  }
  cout<<"Conta criada"<<endl;
  }
void Interface::excluirclientei(){
  string cpf_cnpj;
cout <<endl<< "Insira o CPF ou o CNPJ do cliente a ser excluido"<<endl;
getline(cin,cpf_cnpj);
getline(cin,cpf_cnpj);
this->excluirCliente(cpf_cnpj);

}

void Interface::excluircontai(){
  int numConta;
cout <<endl<< "Insira o numero da conta a ser excluida"<<endl;
cin>>numConta;
this->excluirConta(numConta);

}

void Interface::depositoi(){
  int numConta;
  double valor;
cout <<endl<< "Insira o numero da conta a receber o deposito"<<endl;
cin>>numConta;
cout << "Insira o valor a ser depositado"<<endl;
cin>>valor;
this->deposito(numConta, valor);

}

void Interface::saquei(){
  int numConta;
  double valor;
cout << "Insira o numero da conta da qual o saque sera realizado"<<endl;
cin>>numConta;
cout << "Insira o valor a ser sacado"<<endl;
cin>>valor;
this->saque(numConta, valor);

}

void Interface::transferenciai(){
  int oriconta,destconta;
  double valor;
cout <<endl<< "Insira o numero da conta de origem da transferencia"<<endl;
cin>>oriconta;
cout <<"Insira o numero da conta de destino"<<endl;
cin>>destconta;
cout <<"Insira o valor a ser transferido"<<endl;
cin>>valor;

this->transferencia(oriconta,destconta, valor);


}

void Interface::cobrartarifai(){

this->cobrarTarifa();



}
void Interface::cobrarcpmfi(){

  this->cobrarCPMF();


}

void Interface::saldoi()const{

  int numConta;
  double valor;

cout <<endl<< "Insira o numero da conta a se avaliar o saldo"<<endl;
cin>>numConta;
valor = this->obterSaldo(numConta);

if(valor == -1){
cout<< "O numero de conta inserido nao foi encontrado";
}
else{
cout<<"O saldo da conta e de: R$"<<valor<<",00"<<endl;
}
}



void Interface::extratoi(){
  int numConta;
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

extrato = this->obterExtrato(numConta,dini,dfim);
cout<<extrato<<endl;
}

void Interface::listaclientes()const{
std::vector<Cliente> temp;
Cliente clientetemp;
temp = this->obterListaClientes();

for(std::vector<Cliente>::const_iterator i = temp.begin(); i != temp.end(); ++i){
clientetemp =*i;
this->printacliente(clientetemp);
}
}

void Interface::listacontas()const{
  std::vector<Conta> temp;
  Conta contatemp;
  Cliente clientetemp;
  temp = this->obterListaContas();

  for(std::vector<Conta>::const_iterator i = temp.begin(); i != temp.end(); ++i){
  contatemp =*i;
  clientetemp = contatemp.get_cliente();
  this->printaconta(contatemp);
  this->printacliente(clientetemp);

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

void Interface::principal(){

this->lerDados();
int menu=1;
while (menu!=0)
{
menu = this->menu();
}
this->gravarDados();
}
