#ifndef MIDIA_H
#define MIDIA_H

#include <iostream>
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

enum RAMO {
	LIVRO,
	CD,
	DVD
};

#include "Data.h"

class Midia {
	protected:
		RAMO ramo;

		string titulo;
		string autor;
		Data anoLancamento;

		void dadosMidia(istream &i);

		virtual void exibirDados(ostream &o) const = 0;

	public:
		static int id;

		Midia(RAMO ramo, string titulo, string autor, Data anoLancamento);
		Midia();
		virtual ~Midia();

		RAMO getRamo();

		int getId();

		void setTitulo(string titulo);
		string getTitulo();

		void setAutor(string autor);
		string getAutor();

		void setAnoLancamento(Data anoLancamento);
		Data getAnoLancamento();

		friend ostream& operator<< (ostream &o, Midia const &_midia);

		bool operator== (Midia const &_m) {return (_m.id == this->id) ? true : false;}

		bool operator> (Midia const &_m) {return (_m.titulo > this->titulo) ? true : false;}

};

#endif 