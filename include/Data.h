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

		char separador;

	public:
		Data(int dia, int mes, int ano);
		Data();
		~Data();

		void setSeparador(char separador);

		void setDia(int dia);
		int getDia();

		void setMes(int mes);
		int getMes();

		void setAno(int ano);
		int getAno();

		friend ostream& operator<<(ostream &o, Data const &_data);

		friend istream& operator>>(istream &i, Data &_data);

};

#endif

