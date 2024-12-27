#include "ListaProfe.h"

ListaProfes::ListaProfes() {
    primero = NULL;
    actual = NULL;
}

ListaProfes::~ListaProfes() {
    while (primero != NULL) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

void ListaProfes::agregarInicio(Profe* profe) {
    actual = new NodoProfe(profe, NULL);
    if (primero == NULL) {
        primero = actual;
    }
    else {
        actual->setSiguiente(primero);
        primero = actual;
    }
}

bool ListaProfes::eliminarInicio() {
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
void ListaProfes::guardarEnArchivo() {
    ofstream archivo("Archivos/profesores.txt", ios::out);
    if (archivo) {
        NodoProfe* actual = primero;
        while (actual != nullptr) {
            archivo << actual->getInfo()->getNombre() << endl;
            archivo << actual->getInfo()->getId() << endl;
            archivo << actual->getInfo()->getTelefono() << endl;
            archivo << actual->getInfo()->getEmail() << endl;
            archivo << actual->getInfo()->getGradoAcademico() << endl;
            archivo << "---" << endl;
            actual = actual->getSiguiente();
        }
        archivo.close();
        cout << "Profesores guardados en 'profesores.txt' correctamente.\n";
    }
    else {
        cout << "Error al abrir de 'profesores.txt' para guardar.\n";
    }
}

void ListaProfes::cargarDesdeArchivo() {
    ifstream archivo("Archivos/profesores.txt", ios::in);
    if (archivo) {
        string nombre, id, email, gradoAcademico, linea, telefono;


        while (getline(archivo, nombre)) {
            if (!nombre.empty()) {
                getline(archivo, id);
                archivo >> telefono;
                archivo.ignore();
                getline(archivo, email);
                getline(archivo, gradoAcademico);
                getline(archivo, linea);

                if (buscarProfe(id) == nullptr) {
                    agregarInicio(new Profe(nombre, id, telefono, email, gradoAcademico));
                }
            }
        }
        archivo.close();
        cout << "Profesores cargados desde 'profesores.txt' correctamente.\n";
    }
    else {
        cout << "Error al cargar el archivo de 'profesores.txt'.\n";
    }
}

string ListaProfes::toStringProfes() {
    string resultado;
    NodoProfe* temp = primero;
    while (temp != nullptr) {
        resultado += temp->toStringNodoProfe() + "\n";
        temp = temp->getSiguiente();
    }
    return resultado;
}

bool ListaProfes::listaProfeVacia() {
    return primero == nullptr;
}

Profe* ListaProfes::buscarProfe(string id) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getInfo()->getId() == id) {
            return actual->getInfo();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

NodoProfe* ListaProfes::getPrimero() {
    return primero;
}
