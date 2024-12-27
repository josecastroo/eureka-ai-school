#ifndef LISTACURSOS_H
#define LISTACURSOS_H
#include <iostream>
#include <fstream>
#include "NodoCursos.h"
#include "Curso.h"

using namespace std;

class ListaCursos {
private:
    NodoCurso* primero;
    NodoCurso* actual;

public:
    ListaCursos();
    ~ListaCursos();
    void agregarInicio(Curso* c);
    bool eliminarInicio();
    string toStringCursos();
    bool listaCursoVacia();
    void guardarEnArchivo();
    void cargarDesdeArchivo();
    Curso* buscarCurso(string);
    NodoCurso* getPrimero();
};
#endif
