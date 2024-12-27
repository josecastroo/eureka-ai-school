#include "ListaGrupo.h"

ListaGrupo::ListaGrupo() {
    primero = nullptr;
    actual = nullptr;
}

ListaGrupo::~ListaGrupo() {
    while (!listaVacia()) {
        eliminarInicio();
    }
}

void ListaGrupo::insertarInicio(Grupo* g) {
    NodoGrupo* nuevo = new NodoGrupo(g, primero);
    primero = nuevo;
}

int ListaGrupo::tamano() {
    int contador = 0;
    NodoGrupo* temp = primero;
    while (temp != nullptr) {
        contador++;
        temp = temp->getSiguiente();
    }
    return contador;
}
NodoGrupo* ListaGrupo::getPrimero() {
    return primero;
}

Grupo* ListaGrupo::getGrupo(int index) {
    NodoGrupo* temp = primero;
    int count = 0;
    while (temp != nullptr) {
        if (count == index) {
            return temp->getGrupo();
        }
        count++;
        temp = temp->getSiguiente();
    }
    return nullptr;
}

void ListaGrupo::eliminarInicio() {
    if (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

bool ListaGrupo::listaVacia() {
    return primero == nullptr;
}

Grupo* ListaGrupo::buscarGrupo(int numeroGrupo) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getGrupo()->getNumeroGrupo() == numeroGrupo) {
            return actual->getGrupo();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

void ListaGrupo::guardarEnArchivo() {
    ofstream archivo("Archivos/grupos.txt", ios::out);
    if (archivo.is_open()) {
        NodoGrupo* actual = primero;
        while (actual != nullptr) {
            Grupo* grupo = actual->getGrupo();
            archivo << grupo->getNumeroGrupo() << endl;
            archivo << grupo->getCantidad() << endl;
            archivo << grupo->getCapacidadMax() << endl;

            if (grupo->getCurso() != nullptr) {
                archivo << grupo->getCurso()->getId() << endl;
            }
            else {
                archivo << "Sin curso" << endl;
            }


            if (grupo->getProfesor() != nullptr) {
                archivo << grupo->getProfesor()->getNombre() << endl;
            }
            else {
                archivo << "Sin profesor" << endl;
            }


            if (grupo->getHorario() != nullptr) {
                archivo << grupo->getHorario()->getHoraInicio() << endl;
                archivo << grupo->getHorario()->getHoraFinalizacion() << endl;
                archivo << grupo->getHorario()->getDiasSemanales() << endl;
            }
            else {
                archivo << "Sin horario" << endl;
            }

            archivo << "---" << endl;
            actual = actual->getSiguiente();
        }
        archivo.close();
        cout << "Grupos guardados en 'grupos.txt' correctamente.\n";
    }
    else {
        cout << "Error al abrir de 'grupos.txt' para guardar.\n";
    }
}


string ListaGrupo::toString() {
    stringstream s;
    actual = primero;
    while (actual != nullptr) {
        s << actual->toStringNodoGrupo() << endl;
        actual = actual->getSiguiente();
    }
    return s.str();
}
