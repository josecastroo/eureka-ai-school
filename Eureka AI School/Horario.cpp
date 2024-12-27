#include "Horario.h"

Horario::Horario(string horaIni, string horaFin, string DiasSem) {
    this->horaInicio = horaIni;
    this->horaFinalizacion = horaFin;
    this->diasSemanales = DiasSem;
}

Horario::~Horario() {}

string Horario::getHoraInicio() { return horaInicio; }

string Horario::getHoraFinalizacion() { return horaFinalizacion; }

string Horario::getDiasSemanales() { return diasSemanales; }

void Horario::setHoraInicio(string h) { this->horaInicio = h; }

void Horario::setHoraFinalizacion(string f) { this->horaFinalizacion = f; }

void Horario::setDiasSemanales(string d) { this->diasSemanales = d; }

string Horario::toString() {
    stringstream s;
    s << "Hora de inicio: " << horaInicio << endl;
    s << "Hora de finalizacion: " << horaFinalizacion << endl;
    s << "Dias en que se imparte el curso: " << diasSemanales << endl;
    return s.str();
}

