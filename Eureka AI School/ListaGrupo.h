#ifndef LISTAGRUPO_H
#define LISTAGRUPO_H
#include "NodoGrupo.h"
#include "Grupo.h"

class ListaGrupo {
private:
    NodoGrupo* primero;
    NodoGrupo* actual;

public:
    ListaGrupo();
    ~ListaGrupo();

    void insertarInicio(Grupo*);
    int tamano();
    NodoGrupo* getPrimero();
    Grupo* getGrupo(int);
    void eliminarInicio();
    bool listaVacia();
    Grupo* buscarGrupo(int);
    void guardarEnArchivo();
    string toString();
};
#endif
