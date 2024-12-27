#include "Curso.h"

Curso::Curso(string nombre, string id, string horas, int precio, string estado, Horario* horario) {
	this->nombre = nombre;
	this->id = id;
	this->horas = horas;
	this->precio = precio;
	this->estado = estado;
	this->horario = horario;
}

Curso::~Curso() {}

string Curso::getNombre() { return nombre; }

string Curso::getId() { return id; }

string Curso::getHoras() { return horas; }

int Curso::getPrecio() { return precio; }

string Curso::getEstado() { return estado; }

Horario* Curso::getHorario()
{
	return horario;
}

void Curso::setNombre(string nombre) {
	this->nombre = nombre;
}

void Curso::setId(string ide) {
	this->id = ide;
}

void Curso::setHoras(string hora) {
	this->horas = hora;
}

void Curso::setPrecio(int precio) {
	this->precio = precio;

}
void Curso::setEstado(string estado) {
	this->estado = estado;
}

void Curso::setHorario(Horario* horario)
{
	this->horario = horario;
}

string Curso::toString() {
	stringstream s;
	s << "\n\tNombre del curso: " << nombre << endl;
	s << "\tID del curso: " << id << endl;
	s << "\tHoras totales del curso: " << horas << endl;
	s << "\tPrecio del curso: " << precio << endl;
	s << "\tDisponibilidad: " << estado << endl;
	return s.str();
}
