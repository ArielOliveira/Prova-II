#ifndef LIVRO_H
#define LIVRO_H

#include "Midia.h"

class Livro : public Midia {
	private:
		string editora;
		string ISBN;

	public:
		Livro(string titulo, string autor, Data anoLancamento,
				string editora, string ISBN);
		Livro();
		~Livro();

		void setEditora(string editora);
		string getEditora();

		void setISBN(string ISBN);
		string getISBN();

		friend ostream& operator<<(ostream &o, Livro const &_livro);
};

#endif	