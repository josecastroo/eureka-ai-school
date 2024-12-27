#ifndef PROFE_H
#define PROFE_H
#include"Curso.h"

class Profe {
private:
	string nombre;
	string id;
	string telefono;
	string email;
	string gradoAcademico;

public:
	Profe(string, string, string, string, string);
	~Profe();
	string getNombre();
	string getId();
	string getTelefono();
	string getEmail();
	string getGradoAcademico();

	void setNombre(string);
	void setId(string);
	void setGradoAcademico(string);
	void setTelefono(string);
	void setEmail(string);
	string toString();
};
#endif

