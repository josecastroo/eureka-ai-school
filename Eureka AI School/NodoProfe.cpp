#include "NodoProfe.h"

NodoProfe::NodoProfe(Profe* p, NodoProfe* siguiente) : info(p), sig(siguiente) {}

NodoProfe::~NodoProfe() {
    delete info;
}

void NodoProfe::setInfo(Profe* p) {
    info = p;
}

Profe* NodoProfe::getInfo() {
    return info;
}

void NodoProfe::setSiguiente(NodoProfe* siguiente) {
    sig = siguiente;
}

NodoProfe* NodoProfe::getSiguiente() {
    return sig;
}

string NodoProfe::toStringNodoProfe() {
    return info->toString();
}

