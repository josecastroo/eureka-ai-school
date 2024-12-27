#include "NodoGrupo.h"

NodoGrupo::NodoGrupo(Grupo* g, NodoGrupo* n) {
	this->info = g;
	this->sig = n;

}

NodoGrupo::~NodoGrupo() {
	delete info;
}

Grupo* NodoGrupo::getGrupo() {
	return info;
}

void NodoGrupo::setInfo(Grupo* g) {
	this->info = g;
}
void NodoGrupo::setSiguiente(NodoGrupo* g) {
	this->sig = g;
}
NodoGrupo* NodoGrupo::getSiguiente()
{
	return sig;
}

string NodoGrupo::toStringNodoGrupo() {
	return info->toString();
}

