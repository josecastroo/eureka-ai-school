#ifndef GRUPO_H
#define GRUPO_H
#include <iostream>
#include "Curso.h"
#include "Profe.h"
#include "Horario.h"
#include "ListaEstudiante.h"
#include "Estudiantes.h"

class Grupo {
private:
    int numeroGrupo;
    int cantidad;
    int capacidadMax;
    Curso* curso;
    Horario* horario;
    Profe* profesor;
    ListaEstudiantes* estudiantes;

public:
    Grupo();
    ~Grupo();

    int getNumeroGrupo();
    void setNumeroGrupo(int);
    int getCantidad();
    void setCantidad(int);
    int getCapacidadMax();

    Horario* getHorario();
    void setHorario(Horario*);
    Profe* getProfesor();
    void setProfesor(Profe*);
    void setCapacidadMax(int);

    bool eliminarEstudiante(Estudiantes*);

    Curso* getCurso();
    void setCurso(Curso*);

    bool agregarEstudiante(Estudiantes*);
    bool estudianteInscrito(string);

    string toString();
};
#endif

