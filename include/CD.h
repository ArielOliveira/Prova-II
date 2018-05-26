#ifndef CD_H
#define CD_H

#include "Midia.h"

class Cd : public Midia {
	private:
		int faixas;
		string gravadora;

		void dadosCD(istream &i);

		void exibirDados(ostream &o) const;

	public:
		Cd(string titulo, string autor, Data anoLancamento,
			int faixas, string gravadora);
		Cd();
		~Cd();

		void setFaixas(int faixas);
		int getFaixas();

		void setGravadora(string gravadora);
		string getGravadora();

		friend istream& operator>>(istream &i, Cd &_cd);
};

#endif