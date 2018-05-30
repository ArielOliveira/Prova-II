#include <iostream>
using std::cin;

#include <string>
using std::string;

#include "fileHandler.h"

#include "Acervo.h"

#include "Midia.h"
#include "Livro.h"
#include "CD.h"
#include "DVD.h"

int Midia::id = 0;



int main() {
	Acervo *acervo = new Acervo("Usuario");
	
	Data d = Data(13, 06, 1994);

	Midia *midia = new Livro("umLivro", "umAutor", d, "umaEditora", "ISBN");

	Midia *midia1 = new Dvd("umDvd", "umAutor", d, d, "+18");

	acervo->inserirMidia(midia);
	acervo->inserirMidia(midia1);

	acervo->mostrarAcervo();
	
	return 0;
}