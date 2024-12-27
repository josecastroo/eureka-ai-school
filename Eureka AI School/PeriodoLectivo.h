#ifndef PERIODOLECTIVO_H
#define PERIODOLECTIVO_H
#include <fstream>
#include "ListaGrupo.h"
#include "Grupo.h"

class PeriodoLectivo {
private:
    ListaGrupo* periodo1;
    ListaGrupo* periodo2;
    ListaGrupo* periodo3;
    ListaGrupo* periodo4;

public:
    PeriodoLectivo();
    ~PeriodoLectivo();

    void agregarGrupoPeriodo1(Grupo* g);
    void agregarGrupoPeriodo2(Grupo* g);
    void agregarGrupoPeriodo3(Grupo* g);
    void agregarGrupoPeriodo4(Grupo* g);

    ListaGrupo* getPeriodo1();
    ListaGrupo* getPeriodo2();
    ListaGrupo* getPeriodo3();
    ListaGrupo* getPeriodo4();

    string toStringPeriodo1();
    string toStringPeriodo2();
    string toStringPeriodo3();
    string toStringPeriodo4();
    void guardarEnArchivo();
    ListaGrupo* getPeriodo(int i);
};
#endif
