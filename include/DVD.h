#ifndef DVD_H
#define DVD_H

#include "Midia.h"

class Dvd : public Midia {
	private:
		Data duracao;
		string classificacao;

		void dadosDvd(istream &i);

		void exibirDados(ostream &o) const;

	public:
		Dvd(string titulo, string autor, Data anoLancamento,
			Data duracao, string classificacao);
		Dvd();
		~Dvd();

		void setDuracao(Data duracao);
		Data getDuracao();

		void setClassificacao(string classificacao);
		string getClassificacao();

		friend istream& operator>>(istream &i, Dvd &_dvd);
};

#endif