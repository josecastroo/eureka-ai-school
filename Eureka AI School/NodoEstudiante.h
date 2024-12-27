#ifndef NODOESTUDIANTE_H
#define NODOESTUDIANTE_H
#include"Estudiantes.h"

class NodoEstudiante {
private:
	Estudiantes* info;
	NodoEstudiante* sig;

public:
	NodoEstudiante(Estudiantes*, NodoEstudiante*);
	~NodoEstudiante();
	void setInfo(Estudiantes*);
	Estudiantes* getInfo();
	void setSiguiente(NodoEstudiante*);
	NodoEstudiante* getSiguiente();
	string stringNodoEstudiante();
};
#endif
