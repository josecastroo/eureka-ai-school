#include "NodoEstudiante.h"

NodoEstudiante::NodoEstudiante(Estudiantes* e, NodoEstudiante* n) {
	info = e;
	sig = n;
}
NodoEstudiante::~NodoEstudiante() {
	delete info;
}
void NodoEstudiante::setInfo(Estudiantes* e) {
	info = e;
}
Estudiantes* NodoEstudiante::getInfo() { return info; }

void NodoEstudiante::setSiguiente(NodoEstudiante* s) {
	sig = s;
}
NodoEstudiante* NodoEstudiante::getSiguiente() { return sig; }

string NodoEstudiante::stringNodoEstudiante() {
	return info->toString();
}
