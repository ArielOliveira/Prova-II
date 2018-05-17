#ifndef CD_H
#define CD_H

#include "Midia.h"

class CD : public Midia {
	private:
		int faixas;
		string gravadora;

	public:
		CD(string titulo, string autor, Data anoLancamento,
			int faixas, string gravadora);
		CD();
		~CD();

		void setFaixas(int faixas);
		int getFaixas();

		void setGravadora(string gravadora);
		string getGravadora();

		friend ostream& operator<<(ostream &o, CD const &_cd);
};

#endif