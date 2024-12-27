#include "NodoCursos.h"

NodoCurso::NodoCurso(Curso* c, NodoCurso* s) {
	info = c;
	sig = s;
}
NodoCurso::~NodoCurso() {
	delete info;
}
Curso* NodoCurso::getInfo() { return info; }


NodoCurso* NodoCurso::getSiguiente() { return sig; }

void NodoCurso::setInfo(Curso* c) {
	this->info = c;
}

void NodoCurso::setSiguiente(NodoCurso* s) {
	this->sig = s;
}

string NodoCurso::toStringNodoCurso() {
	return info->toString();
}

