#include "DVD.h"

DVD::DVD(string titulo, string autor, Data anoLancamento,
			Data duracao, string classificacao) : Midia(DVD, titulo, autor, anoLancamento),
												  duracao(duracao), classificacao(classificacao) {}
		
DVD::DVD() {
			duracao = Data();
			classificacao = "";
		}

DVD::~DVD() {}

void DVD::setDuracao(Data duracao) {this->duracao = duracao;}
Data DVD::getDuracao() {return duracao;}

void DVD::setClassificacao(string classificacao) {this->classificacao = classificacao;}
string DVD::getClassificacao() {return classificacao;}

ostream& operator<<(ostream &o, DVD const &_dvd) {
	o << (Midia&)_dvd
	  << _dvd.duracao << endl
	  << _dvd.classificacao << endl;

	return o;
}