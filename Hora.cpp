#include <ctime>
#include "syscelular.h"


using namespace std;
using namespace operadora;


Hora::Hora()
{
	time_t result = time(NULL);
	char arrchar[100];
	ctime_s(arrchar,100,&result);
	
	string stamp(arrchar);

	timestamp_ = stamp;
		
}


string Hora::get_timestamp()
{
	return timestamp_;
}