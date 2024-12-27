#include "Profe.h"

Profe::Profe(string nombre, string id, string numero, string email, string grado) {
	this->nombre = nombre;
	this->id = id;
	this->telefono = numero;
	this->email = email;
	this->gradoAcademico = grado;
}

Profe::~Profe() { }

string Profe::getNombre() { return nombre; }

string Profe::getId() { return id; }

string Profe::getTelefono() { return telefono; }

string Profe::getEmail() { return email; }

string Profe::getGradoAcademico() { return gradoAcademico; }

void Profe::setNombre(string nom) {
	this->nombre = nom;
}

void Profe::setId(string id) {
	this->id = id;
}

void Profe::setTelefono(string tel) {
	this->telefono = tel;
}

void Profe::setEmail(string mail) {
	this->email = mail;
}

void Profe::setGradoAcademico(string g) {
	this->gradoAcademico = g;
}

string Profe::toString() {
	stringstream s;
	s << "Nombre del profesor: " << nombre << endl;
	s << "ID: " << id << endl;
	s << "Numero de telefono: " << telefono << endl;
	s << "Correo: " << email << endl;
	s << "Grado Academico: " << gradoAcademico << endl;
	return s.str();
}
