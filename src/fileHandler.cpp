#include "fileHandler.h"

void readFile(ifstream &file, int line) {
	std::string dummy;
	for (int i = 0; i < line; i++) {
		getline(file, dummy, '\n');
	}
	getline(file, dummy, ';');
}