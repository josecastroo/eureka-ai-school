#include"ListaEstudiante.h"
#include <sstream>
#include <iostream>


ListaEstudiantes::ListaEstudiantes() {
    primero = nullptr;
    actual = nullptr;
}

ListaEstudiantes::~ListaEstudiantes() {
    while (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

void ListaEstudiantes::insertarInicio(Estudiantes* e) {
    actual = new NodoEstudiante(e, primero);
    primero = actual;
}

void ListaEstudiantes::eliminarInicio() {
    if (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

void ListaEstudiantes::guardarEnArchivo() {
    ofstream archivo("Archivos/estudiantes.txt", ios::out);
    if (archivo) {
        NodoEstudiante* actual = primero;
        while (actual != nullptr) {
            archivo << actual->getInfo()->getNombre() << endl;
            archivo << actual->getInfo()->getId() << endl;
            archivo << actual->getInfo()->getTelefono() << endl;
            archivo << actual->getInfo()->getEmail() << endl;
            archivo << actual->getInfo()->getEspecialidad() << endl;
            archivo << "---" << endl;
            actual = actual->getSiguiente();
        }
        archivo.close();
        cout << "Estudiantes guardados en 'estudiantes.txt' correctamente.\n";
    }
    else {
        cout << "Error al abrir de 'estudiantes.txt' para guardar.\n";
    }
}

void ListaEstudiantes::cargarDesdeArchivo() {
    ifstream archivo("Archivos/estudiantes.txt", ios::in);
    if (archivo) {
        string nombre, id, email, especialidad, linea, telefono;


        while (getline(archivo, nombre)) {
            if (!nombre.empty()) {
                getline(archivo, id);
                archivo >> telefono;
                archivo.ignore();
                getline(archivo, email);
                getline(archivo, especialidad);
                getline(archivo, linea);

                // Evitar duplicados
                if (buscarEstudiante(id) == nullptr) {
                    insertarInicio(new Estudiantes(nombre, id, telefono, email, especialidad));
                }
            }
        }
        archivo.close();
        cout << "Estudiantes cargados desde 'estudiantes.txt' correctamente.\n";
    }
    else {
        cout << "Error al cargar el archivo de 'estudiantes.txt'.\n";
    }
}

Estudiantes* ListaEstudiantes::getEstudiante(int index) {
    NodoEstudiante* temp = primero;
    int count = 0;


    while (temp != nullptr) {
        if (count == index) {
            return temp->getInfo();
        }
        count++;
        temp = temp->getSiguiente();
    }


    return nullptr;
}
int ListaEstudiantes::tamano() {
    int count = 0;
    NodoEstudiante* temp = primero;
    while (temp != nullptr) {
        count++;
        temp = temp->getSiguiente();
    }
    return count;
}

bool ListaEstudiantes::eliminarEstudiante(Estudiantes* estudiante) {
    if (primero == nullptr) {
        return false;
    }

    if (primero->getInfo() == estudiante) {
        eliminarInicio();
        return true;
    }

    actual = primero;
    while (actual->getSiguiente() != nullptr) {
        if (actual->getSiguiente()->getInfo() == estudiante) {
            NodoEstudiante* nodoAEliminar = actual->getSiguiente();
            actual->setSiguiente(actual->getSiguiente()->getSiguiente());
            delete nodoAEliminar;
            return true;
        }
        actual = actual->getSiguiente();
    }

    return false;
}

bool ListaEstudiantes::listaVacia() {
    return primero == nullptr;
}

string ListaEstudiantes::toString() {
    stringstream s;
    actual = primero;
    while (actual != nullptr) {
        s << actual->stringNodoEstudiante() << endl;
        actual = actual->getSiguiente();
    }
    return s.str();
}

Estudiantes* ListaEstudiantes::buscarEstudiante(string id) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getInfo()->getId() == id) {
            return actual->getInfo();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}