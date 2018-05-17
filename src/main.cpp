#include <iostream>
using std::cin;

#include "fileHandler.h"

#include "Acervo.h"

#include "Midia.h"
#include "Livro.h"
#include "CD.h"
#include "DVD.h"

int Midia::id = 0;


void lerTeclado(int &valor) {
	string informacao;
	bool valida = true;
	do {
		if (!valida)
			cout << "Entrada Inválida. Tente Novamente!" << endl;
		getline(cin, informacao);
	} while (!(valida = (bool)(stringstream(informacao) >> valor)));
}

void inserirMidia(RAMO ramo, ifstream &file, Acervo *acervo) {
	Midia *midia;

	Livro livro;
	Cd cd;
	Dvd dvd;
	switch(ramo) {
		case LIVRO: livro = Livro();
					file >> livro;
					midia = &livro;
			break;
		case CD: cd = Cd();
				 file >> cd;
				 midia = &cd;
			break;
		case DVD: dvd = Dvd();
				  file >> dvd;
				  midia = &dvd;
			break;
	}
  	
  	acervo->inserirMidia(*midia);
}

bool selecioneMidia(Acervo *acervo, ifstream &file) {
	int midia;

	cout << "Selecione a Midia" << endl;
	cout << "0 - Livro" << endl;
	cout << "1 - CD" << endl;
	cout << "2 - DVD" << endl;

	lerTeclado(midia);

	cout << midia << endl;

	if (midia < 0 || midia > 2 ) {
		cout << "Opção inválida" << endl;
		return false;
	} else {
		file.open("./data/midias.csv");

		if (!file) {
			cout << "Erro ao abrir arquivo!" << endl;
		} else {
			readFile(file, midia);
			inserirMidia((RAMO)midia, file, acervo);
		}
	}

	file.close();

	return true;
}

int continua() {
	int valor;

	cout << "Deseja inserir outra midia?" << endl;
	cout << "0 - Não" << endl;
	cout << "Qualquer outro valor para sim" << endl;

	lerTeclado(valor);

	return valor;
}

int main() {
	int continuar = 1;
	Acervo *acervo = new Acervo("Usuario");
	ifstream file;
	
	while (continuar) {
		selecioneMidia(acervo, file);
		acervo->mostrarAcervo();
	}
	
	
	return 0;
}