#include <iostream>
#include <string>
#include <ctime>
#include <sstream>


#include "syscelular.h"

using namespace operadora;


DataDMA::DataDMA() //data do momento de chamada
{
	time_t segundos;
	segundos = time(NULL);
	int dias_desde_1970 = segundos / (60 * 60 * 24);

	DataDMA epoch(1, 1, 1970);
	int dias_ate_1970 = epoch.n_dias_em_data();

	*this = epoch + dias_ate_1970;
}

DataDMA::DataDMA(int dia, int mes, int ano)
{
  dia_ = dia;
  mes_ = mes;
  ano_ = ano;
}

DataDMA::DataDMA(DataDMA const &d)
{
  dia_ = d.dia_;
  mes_ = d.mes_;
  ano_ = d.ano_;
}

DataDMA::DataDMA(int dias)
{
	*this = data_de_n_dias(dias);	
}


DataDMA DataDMA::data_de_n_dias(int dias)
{
	int y = (10000 * dias + 14780) / 3652425;
	int ddd = dias - (365 * y + y / 4 - y / 100 + y / 400);

	if (ddd < 0)
	{
		y = y - 1;
		ddd = dias - (365 * y + y / 4 - y / 100 + y / 400);
	}

	int mi = (100 * ddd + 52) / 3060;
	int mm = (mi + 2) % 12 + 1;
	int y = y + (mi + 2) / 12;
	int dd = ddd - (mi * 306 + 5) / 10 + 1;

	DataDMA ret(dd, mm, y);
	return ret;
}

int DataDMA::n_dias_em_data() const
{
	int m = (mes_ + 9) % 12;
	int y = ano_ - m / 10;

	return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (dia_ - 1);


}

bool DataDMA::valida() 
{
	int dias = this->n_dias_em_data();
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
	int dias1 = d.n_dias_em_data();
	int dias2 = this->n_dias_em_data();

	return data_de_n_dias(dias1 + dias2);

}

DataDMA DataDMA::operator+(int d)
{
	int dias1 = d;
	int dias2 = this->n_dias_em_data();

	return data_de_n_dias(dias1 + dias2);

}

DataDMA DataDMA::operator-(DataDMA d)
{
	int dias1 = d.n_dias_em_data();
	int dias2 = this->n_dias_em_data();
	DataDMA ret = data_de_n_dias(dias1 + dias2);
	return ret;
}

DataDMA DataDMA::operator=(DataDMA d)
{
	mes_ = d.mes_;
	ano_ = d.ano_;
	dia_ = d.dia_;
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
	if (*this->n_dias_em_data < d.n_dias_em_data) return true;
	else return false;
}

bool DataDMA::operator<=(DataDMA d)
{
	if (*this->n_dias_em_data <= d.n_dias_em_data) return true;
	else return false;
}

bool DataDMA::operator>(DataDMA d)
{
	if (*this->n_dias_em_data > d.n_dias_em_data) return true;
	else return false;
}

bool DataDMA::operator>=(DataDMA d)
{
	if (*this->n_dias_em_data >= d.n_dias_em_data) return true;
	else return false;
}