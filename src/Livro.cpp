#include "Livro.h"

Livro::Livro(string titulo, string autor, Data anoLancamento,
				string editora, string ISBN) : Midia(LIVRO, titulo, autor, anoLancamento),
												editora(editora), ISBN(ISBN) {}

Livro::Livro() : Midia() {
	editora = "";
	ISBN = "";
}

void Livro::setEditora(string editora) {this->editora = editora;}
string Livro::getEditora() {return editora;}

void Livro::setISBN(string ISBN) {this->ISBN = ISBN;}
string Livro::getISBN() {return ISBN;}

void Livro::dadosLivro(istream &i) {
	string valor;

	getline(i, valor, ';');
	stringstream(valor) >> editora;

	getline(i, valor, ';');
	stringstream(valor) >> ISBN;
}

ostream& operator<<(ostream &o, Livro const &_livro) {
	o << (Midia&)_livro
	  << "Editora: " << _livro.editora << endl
	  << "ISBN: " << _livro.ISBN << endl;

	return o;
}

istream& operator>>(istream &i, Livro &_livro) {
	_livro.dadosMidia(i);
	_livro.dadosLivro(i);

	return i;
}