#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H
#include <sstream>
using namespace std;

class Estudiantes {
private:
    string nombre;
    string id;
    string especialidad;
    string telefono;
    string email;

public:
    Estudiantes(string, string, string, string, string);
    ~Estudiantes();

    string getNombre();
    string getId();
    string getEspecialidad();
    string getTelefono();
    string getEmail();

    void setNombre(string);
    void setId(string);
    void setEspecialidad(string);
    void setTelefono(string);
    void setEmail(string);

    string toString();
};
#endif

