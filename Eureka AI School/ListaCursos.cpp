#include "ListaCursos.h"
#include <sstream>

ListaCursos::ListaCursos() {
    primero = nullptr;
    actual = nullptr;
}

ListaCursos::~ListaCursos() {
    while (primero != NULL) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

void ListaCursos::agregarInicio(Curso* c) {
    actual = new NodoCurso(c, primero);
    if (primero == NULL) {
        primero = actual;
    }
    else {
        actual->setSiguiente(primero);
        primero = actual;
    }
}

bool ListaCursos::eliminarInicio() {
    if (primero == NULL) {

        return false;
    }
    else {

        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
        return true;
    }
}
string ListaCursos::toStringCursos() {
    stringstream s;
    actual = primero;
    while (actual != nullptr) {
        s << actual->toStringNodoCurso();
        actual = actual->getSiguiente();
    }
    return s.str();
}

bool ListaCursos::listaCursoVacia() {
    return  (primero == NULL) ? true : false;
}

void ListaCursos::guardarEnArchivo() {
    ofstream archivo("Archivos/cursos.txt", ios::out);
    if (archivo.is_open()) {
        NodoCurso* actual = primero;
        while (actual != nullptr) {
            Curso* curso = actual->getInfo();
            archivo << curso->getNombre() << endl;
            archivo << curso->getId() << endl;
            archivo << curso->getHoras() << endl;
            archivo << to_string(curso->getPrecio()) << endl;
            archivo << curso->getEstado() << endl;

            if (curso->getHorario() != nullptr) {
                archivo << curso->getHorario()->getHoraInicio() << endl;
                archivo << curso->getHorario()->getHoraFinalizacion() << endl;
                archivo << curso->getHorario()->getDiasSemanales() << endl;
            }
            else {
                archivo << "Sin horario" << endl;
            }

            archivo << "---" << endl;
            actual = actual->getSiguiente();
        }
        archivo.close();
        cout << "Cursos guardados en 'cursos.txt' correctamente.\n";
    }
    else {
        cout << "Error al abrir el archivo de 'cursos.txt' para guardar.\n";
    }
}

void ListaCursos::cargarDesdeArchivo() {
    ifstream archivo("Archivos/cursos.txt", ios::in);
    if (archivo.is_open()) {
        string nombre, id, horas, estado, linea, horaInicio, horaFinalizacion, diasSemanales;
        string precioStr;
        int precio;

        while (getline(archivo, nombre)) {
            if (!nombre.empty()) {
                getline(archivo, id);
                getline(archivo, horas);

                getline(archivo, precioStr);
                precio = stoi(precioStr);

                getline(archivo, estado);

                getline(archivo, horaInicio);
                Horario* horario = nullptr;
                if (horaInicio != "Sin horario") {
                    getline(archivo, horaFinalizacion);
                    getline(archivo, diasSemanales);
                    horario = new Horario(horaInicio, horaFinalizacion, diasSemanales);
                }

                getline(archivo, linea);

                Curso* curso = new Curso(nombre, id, horas, precio, estado, horario);
                agregarInicio(curso);
            }
        }
        archivo.close();
        cout << "Cursos cargados desde 'cursos.txt' correctamente.\n";
    }
    else {
        cout << "Error al cargar el archivo de 'cursos.txt'.\n";
    }
}


Curso* ListaCursos::buscarCurso(string id) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getInfo()->getId() == id) {
            return actual->getInfo();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

NodoCurso* ListaCursos::getPrimero()
{
    return primero;
}
