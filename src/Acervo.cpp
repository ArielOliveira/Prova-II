#include "Acervo.h"

Acervo::Acervo(string usuario) : usuario(usuario) {
	midias = new List<Midia*>();
}

Acervo::Acervo() {
	midias = new List<Midia*>();
	usuario = "";
}
Acervo::~Acervo() {}

bool Acervo::inserirMidia(Midia midia) {
	if (midias->getSize() > 1) {
		for(int i = 0; i < midias->getSize(); i++) {
			if (midia == *midias->getData(i)) 
				return false;
		}
	}
	midias->insertAtHead(&midia);

	return true;
}

bool Acervo::removerMidia(int id) {
	for(int i = 0; i < midias->getSize(); i++) {
		if (midias->getData(i)->getId() == id) {
			midias->removeAt(i);
			return true;
		}
	}

	return false;
}

void Acervo::mostrarAcervo() {
	midias->printList();
}

void Acervo::setUsuario(string usuario) {this->usuario = usuario;}
string Acervo::getUsuario() {return usuario;}

ostream& operator<< (ostream &o, Acervo const &_acervo);