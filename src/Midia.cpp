#include "Midia.h"

Midia::Midia(RAMO ramo, string titulo, string autor, Data anoLancamento) :  ramo(ramo),
																			titulo(titulo), 
																			autor(autor), 
																			anoLancamento(anoLancamento) {
	id++;
}

Midia::Midia() {
	titulo = "";
	autor = "";
	anoLancamento = Data();

	id++;
}

Midia::~Midia() {}

int Midia::getId() {return id;}

RAMO Midia::getRamo() {return ramo;}

void Midia::dadosMidia(istream &i) {
	string valor;

	getline(i, valor, ';');
	stringstream(valor) >> titulo;

	getline(i, valor, ';');
	stringstream(valor) >> autor;

	i >> anoLancamento;
	i.ignore();
}

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