#include "Grupo.h"

Grupo::Grupo() {
    this->numeroGrupo = 0;
    this->cantidad = 0;
    this->capacidadMax = 0;
    this->curso = nullptr;
    this->horario = nullptr;
    this->profesor = nullptr;
    this->estudiantes = new ListaEstudiantes();
}

Grupo::~Grupo() {
    delete estudiantes;
}

int Grupo::getNumeroGrupo() { return numeroGrupo; }
void Grupo::setNumeroGrupo(int numero) { this->numeroGrupo = numero; }

int Grupo::getCantidad() { return cantidad; }
void Grupo::setCantidad(int cant) { this->cantidad = cant; }

int Grupo::getCapacidadMax()
{
    return capacidadMax;
}

Horario* Grupo::getHorario() { return horario; }
void Grupo::setHorario(Horario* nuevoHorario) {
    this->horario = nuevoHorario;
}

Profe* Grupo::getProfesor() { return profesor; }
void Grupo::setProfesor(Profe* nuevoProfesor) {
    this->profesor = nuevoProfesor;
}

void Grupo::setCapacidadMax(int i)
{
    this->capacidadMax = i;
}

bool Grupo::eliminarEstudiante(Estudiantes* estudiante) {

    return estudiantes->eliminarEstudiante(estudiante);
}

Curso* Grupo::getCurso() { return curso; }
void Grupo::setCurso(Curso* nuevoCurso) {
    this->curso = nuevoCurso;
}

bool Grupo::agregarEstudiante(Estudiantes* nuevoEstudiante) {
    if (nuevoEstudiante != nullptr && cantidad < capacidadMax) {
        estudiantes->insertarInicio(nuevoEstudiante);
        cantidad++;
        return true;
    }
    return false;
}

bool Grupo::estudianteInscrito(string estudianteId) {
    return estudiantes->buscarEstudiante(estudianteId);
}

string Grupo::toString() {
    stringstream s;
    s << "Grupo " << numeroGrupo << endl;
    s << "Capacidad maxima: " << capacidadMax << endl;
    s << "Cantidad actual: " << cantidad << endl;
    s << "Curso: " << (curso ? curso->getNombre() : "Sin asignar") << endl;
    s << "Profesor: " << (profesor ? profesor->getNombre() : "Sin asignar") << endl;
    s << "Horario: " << curso->getHorario()->toString() << endl;
    s << "Estudiantes: " << endl;
    s << estudiantes->toString();
    return s.str();
}
