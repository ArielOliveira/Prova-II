#include "DVD.h"

Dvd::Dvd(string titulo, string autor, Data anoLancamento,
			Data duracao, string classificacao) : Midia(DVD, titulo, autor, anoLancamento),
												  duracao(duracao), classificacao(classificacao) {
		duracao.setSeparador(':');
}
		
Dvd::Dvd() {
			duracao = Data();
			duracao.setSeparador(':');
			classificacao = "";
		}

Dvd::~Dvd() {}

void Dvd::setDuracao(Data duracao) {this->duracao = duracao;}
Data Dvd::getDuracao() {return duracao;}

void Dvd::setClassificacao(string classificacao) {this->classificacao = classificacao;}
string Dvd::getClassificacao() {return classificacao;}

void Dvd::dadosDvd(istream &i) {
	string valor;

	i >> duracao;
	i.ignore();

	getline(i, valor, ';');
	stringstream(valor) >> classificacao;
}

ostream& operator<<(ostream &o, Dvd const &_dvd) {
	o << (Midia&)_dvd
	  << "Duração: " << _dvd.duracao << endl
	  << "Classificação: " << _dvd.classificacao << endl;

	return o;
}

istream& operator>>(istream &i, Dvd &_dvd) {
	_dvd.dadosMidia(i);

	return i;
}