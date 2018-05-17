#include <iostream>
using std::cin;

#include "fileHandler.h"

#include "Acervo.h"

#include "Midia.h"
#include "Livro.h"
#include "CD.h"
#include "DVD.h"

int Midia::id = 0;


void lerTeclado(int valor) {
	string informacao;
	bool valida = true;
	do {
		if (!valida)
			cout << "Entrada Inválida. Tente Novamente!" << endl;
		getline(cin, informacao);
	} while (!(valida = (bool)(stringstream(informacao) >> valor)));
}

int main() {
	int midia = 0;

	Acervo acervo = Acervo("Usuario");

	Livro *livro = new Livro();


	ifstream file;
	file.open("./data/midias.csv");

	if (!file) {
		cout << "Erro ao abrir arquivo!" << endl;
	} else {
		readFile(file, midia);
		file >> *livro;

	}

	acervo.inserirMidia(livro);

	
	return 0;
}