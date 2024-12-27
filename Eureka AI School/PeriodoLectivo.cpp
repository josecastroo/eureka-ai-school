#include "PeriodoLectivo.h"

PeriodoLectivo::PeriodoLectivo() {
    periodo1 = new ListaGrupo();
    periodo2 = new ListaGrupo();
    periodo3 = new ListaGrupo();
    periodo4 = new ListaGrupo();
}

PeriodoLectivo::~PeriodoLectivo() {
    delete periodo1;
    delete periodo2;
    delete periodo3;
    delete periodo4;
}

void PeriodoLectivo::agregarGrupoPeriodo1(Grupo* g) {
    if (g != nullptr) {
        periodo1->insertarInicio(g);
    }
}

void PeriodoLectivo::agregarGrupoPeriodo2(Grupo* g) {
    if (g != nullptr) {
        periodo2->insertarInicio(g);
    }
}

void PeriodoLectivo::agregarGrupoPeriodo3(Grupo* g) {
    if (g != nullptr) {
        periodo3->insertarInicio(g);
    }
}

void PeriodoLectivo::agregarGrupoPeriodo4(Grupo* g) {
    if (g != nullptr) {
        periodo4->insertarInicio(g);
    }
}

ListaGrupo* PeriodoLectivo::getPeriodo1() {
    return periodo1;
}

ListaGrupo* PeriodoLectivo::getPeriodo2() {
    return periodo2;
}

ListaGrupo* PeriodoLectivo::getPeriodo3() {
    return periodo3;
}

ListaGrupo* PeriodoLectivo::getPeriodo4() {
    return periodo4;
}

string PeriodoLectivo::toStringPeriodo1() {
    return periodo1->toString();
}

string PeriodoLectivo::toStringPeriodo2() {
    return periodo2->toString();
}

string PeriodoLectivo::toStringPeriodo3() {
    return periodo3->toString();
}

string PeriodoLectivo::toStringPeriodo4() {
    return periodo4->toString();
}

void PeriodoLectivo::guardarEnArchivo() {
    ofstream archivo("Archivos/periodo_lectivo.txt", ios::out);
    if (archivo.is_open()) {
        for (int i = 1; i <= 4; ++i) {
            ListaGrupo* periodo = getPeriodo(i);
            archivo << "Periodo " << i << endl;
            NodoGrupo* actual = periodo->getPrimero();
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
            archivo << "===" << endl;
        }
        archivo.close();
        cout << "Datos de los periodos lectivos guardados en 'periodo_lectivo.txt' correctamente.\n";
    }
    else {
        cout << "Error al abrir el archivo de 'periodo_lectivo.txt' para guardar.\n";
    }
}
