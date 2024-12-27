#ifndef LISTAESTUDIANTES_H
#define LISTAESTUDIANTES_H
#include <fstream>
#include "Estudiantes.h"
#include "NodoEstudiante.h"
using namespace std;

class ListaEstudiantes {
private:
    NodoEstudiante* primero;
    NodoEstudiante* actual;

public:
    ListaEstudiantes();
    ~ListaEstudiantes();

    void insertarInicio(Estudiantes*);
    void eliminarInicio();
    void guardarEnArchivo();
    void cargarDesdeArchivo();
    Estudiantes* getEstudiante(int);
    int tamano();
    bool eliminarEstudiante(Estudiantes*);
    bool listaVacia();
    Estudiantes* buscarEstudiante(string);

    string toString();
};
#endif
