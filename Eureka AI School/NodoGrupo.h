#ifndef NODOGRUPO_H
#define NODOGRUPO_H
#include"Grupo.h"

class NodoGrupo {
private:
	Grupo* info;
	NodoGrupo* sig;

public:
	NodoGrupo(Grupo*, NodoGrupo*);
	~NodoGrupo();
	void setInfo(Grupo*);
	Grupo* getGrupo();
	void setSiguiente(NodoGrupo*);
	NodoGrupo* getSiguiente();
	string toStringNodoGrupo();
};
#endif