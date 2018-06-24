#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

#include "banksys.h"
using namespace banco;

// dd|mm|aaaa
Data::Data(std::string dataformatada)
{
  std::string dform = dataformatada;
  std::istringstream sdata(dform);

  std::string dia;
  std::string mes;
  std::string ano;

  getline(sdata, dia, '-');
  getline(sdata, mes, '-');
  getline(sdata, ano, '-');

  dia_ = stoi(dia);
  mes_ = stoi(mes);
  ano_ = stoi(ano);
}

Data::Data()
{
  time_t agora = time(NULL);
  //formato time_t para data em string C:
  // www mmm dd hh:mm:ss yyyy
  std::string sd(ctime(&agora));
  //cout << sd;
  std::string sdia = "";
  std::string smes = "";
  std::string sano = "";

  sdia += sd[8]; sdia += sd[9];
  smes += sd[4]; smes += sd[5]; smes += sd[6];
  sano += sd[20]; sano += sd[21]; sano += sd[22]; sano += sd[23];

  dia_ = std::stoi(sdia);

  if (smes == "Jan") mes_ = 1;
  if (smes == "Feb") mes_ = 2;
  if (smes == "Mar") mes_ = 3;
  if (smes == "Apr") mes_ = 4;
  if (smes == "May") mes_ = 5;
  if (smes == "Jun") mes_ = 6;
  if (smes == "Jul") mes_ = 7;
  if (smes == "Aug") mes_ = 8;
  if (smes == "Sep") mes_ = 9;
  if (smes == "Oct") mes_ = 10;
  if (smes == "Nov") mes_ = 11;
  if (smes == "Dec") mes_ = 12;


  ano_ = std::stoi(sano);

  // objeto data carrega consigo o momento em que
  // o construtor foi chamado
}

Data::Data(int dia, int mes, int ano)
{
  dia_ = dia;
  mes_ = mes;
  ano_ = ano;
}

Data::Data(Data const &d)
{
  dia_ = d.dia_;
  mes_ = d.mes_;
  ano_ = d.ano_;
}



/*
time_t Data::get_data_unix()
{
  return agora_;
}
*/


int Data::get_dia()const
{
  return dia_;
}



int Data::get_mes()const
{
  return mes_;
}

int Data::get_ano()const
{
  return ano_;
}

std::string Data::get_data_formatada()
{
/*
  time_t unix_;
  //faco uma copia pq essas funcoes malucas
  // de tempo alteram a variavel de entrada,
  //repare que a entrada eh passada por referencia

  //formato time_t para data em string C:
  // www mmm dd hh:mm:ss yyyy
  std::string sd(ctime(&unix_));
  //cout << sd;
  std::string ret = "";

  ret += sd[8]; ret += sd[9]; ret += " ";
  ret += sd[4]; ret += sd[5]; ret += sd[6]; ret += " ";
  ret += sd[20]; ret += sd[21]; ret += sd[22]; ret += sd[23];
*/

  return IntToString(get_dia()) + "-" + IntToString(get_mes()) +
  "-" + IntToString(get_ano());

}




bool Data::operator>(Data d)
{
  if (ano_ > d.ano_) return true;
  if (ano_ < d.ano_) return false;

  if (mes_ > d.mes_) return true;
  if (mes_ < d.mes_) return false;

  if (dia_ > d.dia_) return true;
  return false;
}

bool Data::operator<(Data d)
{
  if (ano_ < d.ano_) return true;
  if (ano_ > d.ano_) return false;

  if (mes_ < d.mes_) return true;
  if (mes_ > d.mes_) return false;

  if (dia_ < d.dia_) return true;
  return false;
}

bool Data::operator==(Data d)
{
  if (ano_ == d.ano_)
  {
    if (mes_ == d.mes_)
    {
      if (dia_ == d.dia_)
      {
        return true;
      }
    }
  }
  return false;
}

bool Data::operator>=(Data d)
{
  if ((*this) > d || (*this) == d) return true;
  else return false;
}

bool Data::operator<=(Data d)
{
  if ((*this) < d || (*this) == d) return true;
  else return false;
}
