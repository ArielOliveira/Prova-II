#include "Data.h"

Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}
		
Data::Data() {
			dia = 0;
			mes = 0;
			ano = 0;
		}

Data::~Data() {}

void Data::setDia(int dia) {this->dia = dia;}
int Data::getDia() {return dia;}

void Data::setMes(int mes) {this->mes = mes;}
int Data::getMes() {return mes;}

void Data::setAno(int ano) {this->ano = ano;}
int Data::getAno() {return ano;}


ostream& operator<<(ostream &o, Data const &_data) {
	o << _data.dia << "/" << _data.mes << "/" << _data.ano;

	return o;
}

istream& operator>>(istream &i, Data &_data) {
	i >> _data.dia;
	i.ignore();

	i >> _data.mes;
	i.ignore();

	i >> _data.ano;

	return i;
}