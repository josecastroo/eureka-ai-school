#ifndef LISTAPROFE_H
#define LISTAPROFE_H
#include <iostream>
#include <fstream>
#include "NodoProfe.h"
using namespace std;

class ListaProfes {
private:
    NodoProfe* primero;
    NodoProfe* actual;
public:
    ListaProfes();
    ~ListaProfes();

    void agregarInicio(Profe*);
    bool eliminarInicio();
    void guardarEnArchivo();
    void cargarDesdeArchivo();

    string toStringProfes();
    bool listaProfeVacia();
    Profe* buscarProfe(string);
    NodoProfe* getPrimero();
};
#endif

