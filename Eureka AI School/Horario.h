#ifndef HORARIO_H
#define HORARIO_H
#include <iostream>
#include <sstream>
using namespace std;

class Horario {
private:
    string horaInicio;
    string horaFinalizacion;
    string diasSemanales;

public:
    Horario(string, string, string);
    ~Horario();

    string getHoraInicio();
    string getHoraFinalizacion();
    string getDiasSemanales();

    void setHoraInicio(string);
    void setHoraFinalizacion(string);
    void setDiasSemanales(string);

    string toString();
};
#endif
