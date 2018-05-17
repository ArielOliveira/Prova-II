#include "Midia.h"

Midia::Midia(string titulo, string autor, Data anoLancamento) : titulo(titulo), 
																autor(autor), 
																anoLancamento(anoLancamento) {}

Midia::Midia() {
	titulo = "";
	autor = "";
	anoLancamento = Data();
}

Midia::~Midia() {}

RAMO getRamo() {return ramo;}

void Midia::dadosMidia(istream &i) {}

void Midia::setTitulo(string titulo) {this->titulo = titulo;}
string Midia::getTitulo() {return titulo;}

void Midia::setAutor(string autor) {this->autor = autor;}
string Midia::getAutor() {return autor;}

void Midia::setAnoLancamento(Data anoLancamento) {this->anoLancamento = anoLancamento;}
Data Midia::getAnoLancamento() {return anoLancamento;}

ostream& operator<< (ostream &o, Midia const &_midia) {
	o << "Titulo: " << _midia.titulo << endl
	  << "Autor: " << _midia.autor << endl
	  << "Ano de Lançamento: " << _midia.anoLancamento << endl;

	return o;
}