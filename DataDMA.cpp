#include <iostream>
#include <string>
#include <ctime>
#include <sstream>


#include "syscelular.h"

using namespace tp2;


DataDMA::DataDMA() //data do momento de chamada
{
	time_t segundos;
	segundos = time(nullptr);
	long dias_desde_1970 = segundos / (60 * 60 * 24);

	DataDMA epoch(31, 12, 1969);
	long dias_ate_1970 = epoch.n_dias_em_data();

	*this = data_de_n_dias(dias_desde_1970 + dias_ate_1970);

}

DataDMA::DataDMA(int dia, int mes, int ano)
{
  dia_ = dia;
  mes_ = mes;
  ano_ = ano;
  if (!this->valida()) throw  ExceptData("Data Invalida");
}

DataDMA::DataDMA(DataDMA const &d)
{
  dia_ = d.dia_;
  mes_ = d.mes_;
  ano_ = d.ano_;
}

DataDMA::DataDMA( long dias)
{
	*this = data_de_n_dias(dias);
}


DataDMA DataDMA::data_de_n_dias(int dias)
{
	double y = floor((10000.0 * dias + 14780.0) / 3652425.0);

	long ddd = dias - (365 * y + y / 4 - y / 100 + y / 400);

	if (ddd < 0)
	{
		y = y - 1;
		ddd = dias - (365 * y + y / 4 - y / 100 + y / 400);
	}

	unsigned long mi = (100 * ddd + 52) / 3060;
	unsigned long mm = (mi + 2) % 12 + 1;
	y = y + (mi + 2) / 12;
	long dd = ddd - (mi * 306 + 5) / 10 + 1;

	DataDMA ret(dd, mm, y);
	return ret;
}

long DataDMA::n_dias_em_data()
{
	long m = (mes_ + 9) % 12;
	long y = ano_ - m / 10;

	long ret = 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (dia_ - 1);
	ret += 1;
	return ret;


}

bool DataDMA::valida()
{
	long dias = this->n_dias_em_data();
	if ((*this) == data_de_n_dias(dias))
	{
		return true;
	}
	else return false;
}

int DataDMA::get_dia() const
{
	return dia_;
}

int DataDMA::get_mes() const
{
	return mes_;
}

int DataDMA::get_ano() const
{
	return ano_;
}




DataDMA DataDMA::operator+(DataDMA d)
{
	long dias1 = d.n_dias_em_data();
	long dias2 = this->n_dias_em_data();

	return data_de_n_dias(dias1 + dias2);

}

DataDMA DataDMA::operator+(long d)
{
	long dias1 = d;
	long dias2 = this->n_dias_em_data();

	return data_de_n_dias(dias1 + dias2);

}

DataDMA DataDMA::operator-(DataDMA d)
{
	long dias1 = d.n_dias_em_data();
	long dias2 = this->n_dias_em_data();
	DataDMA ret = data_de_n_dias(dias1 + dias2);
	return ret;
}

DataDMA DataDMA::operator=(DataDMA d)
{
	mes_ = d.mes_;
	ano_ = d.ano_;
	dia_ = d.dia_;
	return *this;
}

bool DataDMA::operator==(DataDMA d)
{
	if( mes_ == d.mes_ &&
		ano_ == d.ano_ &&
		dia_ == d.dia_)
	{
		return true;
	}
	else return false;
}

bool DataDMA::operator<(DataDMA d)
{
	if ((this->n_dias_em_data()) < d.n_dias_em_data()) return true;
	else return false;
}

bool DataDMA::operator<=(DataDMA d)
{
	if ((this->n_dias_em_data()) <= d.n_dias_em_data()) return true;
	else return false;
}

bool DataDMA::operator>(DataDMA d)
{
	if ((this->n_dias_em_data()) > d.n_dias_em_data()) return true;
	else return false;
}

bool DataDMA::operator>=(DataDMA d)
{
	if ((this->n_dias_em_data()) >= d.n_dias_em_data()) return true;
	else return false;
}
