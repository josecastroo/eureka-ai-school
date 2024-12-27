#ifndef CURSO_H
#define CURSO_H
#include <iostream>
#include <sstream>
#include "Horario.h"
using namespace std;

class Curso {
private:
    string nombre;
    string id;
    string horas;
    int precio;
    string estado;
    Horario* horario;

public:
    Curso(string, string, string, int, string, Horario*);
    ~Curso();

    string getNombre();
    string getId();
    string getHoras();
    int getPrecio();
    string getEstado();
    Horario* getHorario();

    void setNombre(string);
    void setId(string);
    void setHoras(string);
    void setPrecio(int);
    void setEstado(string);
    void setHorario(Horario*);

    string toString();
};
#endif