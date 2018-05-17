#ifndef DATA_H
#define DATA_H

#include <ostream>
using std::ostream;

#include <istream>
using std::istream;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

class Data {
	private:
		int dia;
		int mes;
		int ano;
	public:
		Data(int dia, int mes, int ano);
		Data();
		~Data();

		void setDia(int dia);
		int getDia();

		void setMes(int mes);
		int getMes();

		void setAno(int ano);
		int getAno();

		friend ostream& operator<<(ostream &o, Data const &_data);

		friend istream& operator>>(istream &i, Data &_data);

		
		Data operator=(string const &_data) {
			int dia, mes, ano;

			stringstream(_data) >> dia;

			stringstream(_data) >> mes;

			stringstream(_data) >> ano;

			return Data(dia, mes, ano);
		}

};

#endif

