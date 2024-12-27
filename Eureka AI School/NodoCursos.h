#ifndef NODOCURSOS_H
#define NODOCURSOS_H
#include"Curso.h"

class NodoCurso {
private:
	Curso* info;
	NodoCurso* sig;

public:
	NodoCurso(Curso*, NodoCurso*);
	~NodoCurso();
	void setInfo(Curso*);
	Curso* getInfo();
	void setSiguiente(NodoCurso*);
	NodoCurso* getSiguiente();
	string toStringNodoCurso();

};
#endif
