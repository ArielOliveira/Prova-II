#ifndef MIDIA_H
#define MIDIA_H

#include <iostream>
using std::endl;

#include <string>
using std::string;

enum RAMO {
	LIVRO,
	CD,
	DVD
};

#include "Data.h"

class Midia {
	private:
		RAMO ramo;

		string titulo;
		string autor;
		Data anoLancamento;

		void dadosMidia(istream &i);

		virtual void dados(istream &i) = 0;

	public:
		Midia(RAMO ramo, string titulo, string autor, Data anoLancamento);
		Midia();
		~Midia();

		RAMO getRamo();

		void setTitulo(string titulo);
		string getTitulo();

		void setAutor(string autor);
		string getAutor();

		void setAnoLancamento(Data anoLancamento);
		Data getAnoLancamento();

		friend ostream& operator<< (ostream &o, Midia const &_midia);
};

#endif 