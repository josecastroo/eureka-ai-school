#ifndef MATRICULA_H
#define MATRICULA_H
#include <iostream>
#include <sstream>
#include "ListaEstudiante.h"
#include "PeriodoLectivo.h"
#include "Grupo.h"
#include "Estudiantes.h"
using namespace std;

class Matricula {
private:
    ListaEstudiantes* estudiantesMatriculados;
    PeriodoLectivo* periodoLectivo;

public:
    Matricula(PeriodoLectivo*);
    ~Matricula();

    bool matricularEstudiante(Estudiantes*, Grupo*);
    void generarFactura();
    bool desmatricularEstudiante(Estudiantes*, Grupo*);
    void buscarEstudianteYListarGrupos(string);
};
#endif

