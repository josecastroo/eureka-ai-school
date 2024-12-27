#include "Estudiantes.h"

Estudiantes::Estudiantes(string nombre, string id, string especialidad, string telefono, string email) {
    this->nombre = nombre;
    this->id = id;
    this->especialidad = especialidad;
    this->telefono = telefono;
    this->email = email;
}

Estudiantes::~Estudiantes() {}

string Estudiantes::getNombre() {
    return nombre;
}

string Estudiantes::getId() {
    return id;
}

string Estudiantes::getEspecialidad() {
    return especialidad;
}

string Estudiantes::getTelefono() {
    return telefono;
}

string Estudiantes::getEmail() {
    return email;
}

void Estudiantes::setNombre(string nombre) {
    this->nombre = nombre;
}

void Estudiantes::setId(string id) {
    this->id = id;
}

void Estudiantes::setEspecialidad(string esp) {
    this->especialidad = esp;
}

void Estudiantes::setTelefono(string tel) {
    this->telefono = tel;
}

void Estudiantes::setEmail(string email) {
    this->email = email;
}

string Estudiantes::toString() {
    stringstream s;
    s << "Nombre del estudiante: " << nombre << endl;
    s << "ID del estudiante: " << id << endl;
    s << "Especialidad: " << especialidad << endl;
    s << "Numero de telefono: " << telefono << endl;
    s << "Correo del estudiante: " << email << endl;
    return s.str();
}
