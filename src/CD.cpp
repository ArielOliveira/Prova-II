#include "CD.h"

CD::CD(string titulo, string autor, Data anoLancamento,
			int faixas, string gravadora) : Midia(titulo, autora, anoLancamento),
											faixas(faixas), gravadora(gravadora) {}

CD() Midia() {
	faixas = 0;
	gravadora = "";
}

~CD() {}


void CD::setFaixas(int faixas) {this->faixas = faixas;}
int CD::getFaixas() {return faixas;}

void CD::setGravadora(string gravadora) {this->gravadora = gravadora;}
string CD::getGravadora() {return gravadora;}

ostream& operator<<(ostream &o, CD const &_cd) {
	o << (Midia&)_cd
	  << _cd.faixas << endl
	  << _cd.gravadora << endl;

	return o;
}

		}