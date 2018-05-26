#ifndef ACERVO_H
#define ACERVO_H

#include "lista.h"
#include "Midia.h"

class Acervo {
	private:
		List<Midia*> *midias;

		string usuario;

	public:
		Acervo(string usuario);
		Acervo();
		~Acervo();

		bool inserirMidia(Midia *midia);

		bool removerMidia(int id);

		void mostrarAcervo();

		void setUsuario(string usuario);
		string getUsuario();

		friend ostream& operator<< (ostream &o, Acervo const &_acervo);

};

#endif