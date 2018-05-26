#include "CD.h"

Cd::Cd(string titulo, string autor, Data anoLancamento, int faixas, string gravadora) : Midia(CD, titulo, autor, anoLancamento),
											faixas(faixas), gravadora(gravadora) {}

Cd::Cd() : Midia() {
	faixas = 0;
	gravadora = "";
}

Cd::~Cd() {}


void Cd::setFaixas(int faixas) {this->faixas = faixas;}
int Cd::getFaixas() {return faixas;}

void Cd::setGravadora(string gravadora) {this->gravadora = gravadora;}
string Cd::getGravadora() {return gravadora;}

void Cd::dadosCD(istream &i) {
	string valor;

	i >> faixas;
	i.ignore();

	getline(i, valor, ';');
	stringstream(valor) >> gravadora;

}

void Cd::exibirDados(ostream &o) const {}

istream& operator>>(istream &i, Cd &_cd) {
	_cd.dadosMidia(i);
	_cd.dadosCD(i);

	return i;

}