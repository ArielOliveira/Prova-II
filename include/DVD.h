#ifndef DVD_H
#define DVD_H

class DVD : public Midia {
	private:
		Data duracao;
		string classificacao;

	public:
		DVD(string titulo, string autor, Data anoLancamento,
			Data duracao, string classificacao);
		DVD();
		~DVD();

		void setDuracao(Data duracao);
		Data getDuracao();

		void setClassificacao(string classificacao);
		string getClassificacao();

		friend ostream& operator<<(ostream &o, DVD const &_dvd);
};

#endif