#include "Matricula.h"

Matricula::Matricula(PeriodoLectivo* periodo) {
    estudiantesMatriculados = new ListaEstudiantes();
    periodoLectivo = periodo;
}

Matricula::~Matricula() {
    delete estudiantesMatriculados;
}

bool Matricula::matricularEstudiante(Estudiantes* estudiante, Grupo* grupo) {
    if (grupo->getCantidad() >= grupo->getCapacidadMax()) {
        cout << "El grupo esta lleno." << endl;
        return false;
    }
    if (grupo->estudianteInscrito(estudiante->getId())) {
        cout << "El estudiante ya se encuentra inscrito en este grupo." << endl;
        return false;
    }

    ListaGrupo* listaGrupos[] = {
        periodoLectivo->getPeriodo1(),
        periodoLectivo->getPeriodo2(),
        periodoLectivo->getPeriodo3(),
        periodoLectivo->getPeriodo4()
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < listaGrupos[i]->tamano(); j++) {
            Grupo* g = listaGrupos[i]->getGrupo(j);
            if (g->getCurso()->getId() == grupo->getCurso()->getId() &&
                g->estudianteInscrito(estudiante->getId())) {
                cout << "El estudiante ya se encuentra inscrito en otro grupo de este curso." << endl;
                return false;
            }
        }
    }

    if (grupo->agregarEstudiante(estudiante)) {
        estudiantesMatriculados->insertarInicio(estudiante);
        cout << "Estudiante matriculado exitosamente del grupo " << grupo->getNumeroGrupo() << endl;
        return true;
    }
    return false;
}

void Matricula::generarFactura() {
    cout << "Factura de matricula:" << endl;
    stringstream factura;
    int total = 0;

    for (int i = 0; i < estudiantesMatriculados->tamano(); i++) {
        Estudiantes* estudiante = estudiantesMatriculados->getEstudiante(i);
        factura << estudiante->getNombre() << " - " << estudiante->getId() << endl;
        factura << "Cursos matriculados: " << endl;

        for (int j = 0; j < 4; j++) {
            ListaGrupo* listaGrupos = periodoLectivo->getPeriodo(j);
            for (int k = 0; k < listaGrupos->tamano(); k++) {
                Grupo* grupo = listaGrupos->getGrupo(k);
                if (grupo->estudianteInscrito(estudiante->getId())) {
                    Curso* curso = grupo->getCurso();
                    factura << "Curso: " << curso->getNombre() << ", Precio: " << curso->getPrecio() << endl;
                    total += curso->getPrecio();
                }
            }
        }
    }
    factura << "Total: " << total << endl;
    cout << factura.str();
}

bool Matricula::desmatricularEstudiante(Estudiantes* estudiante, Grupo* grupo) {
    if (!grupo->estudianteInscrito(estudiante->getId())) {
        cout << "El estudiante no está matriculado en este grupo." << endl;
        return false;
    }
    if (grupo->eliminarEstudiante(estudiante)) {
        cout << "Estudiante desmatriculado exitosamente del grupo " << grupo->getNumeroGrupo() << endl;
        grupo->setCantidad(grupo->getCantidad() - 1);
        return true;
    }
    return false;
}

ListaGrupo* PeriodoLectivo::getPeriodo(int i) {
    switch (i) {
    case 1:
        return periodo1;
    case 2:
        return periodo2;
    case 3:
        return periodo3;
    case 4:
        return periodo4;
    default:
        return nullptr;
    }
}
void Matricula::buscarEstudianteYListarGrupos(string idEstudiante) {
    Estudiantes* estudiante = estudiantesMatriculados->buscarEstudiante(idEstudiante);
    if (estudiante != nullptr) {
        cout << "Estudiante: " << estudiante->getNombre() << endl;

        ListaGrupo* periodos[] = {
            periodoLectivo->getPeriodo1(),
            periodoLectivo->getPeriodo2(),
            periodoLectivo->getPeriodo3(),
            periodoLectivo->getPeriodo4()
        };

        for (int i = 0; i < 4; i++) {
            ListaGrupo* listaGrupos = periodos[i];
            for (int j = 0; j < listaGrupos->tamano(); j++) {
                Grupo* grupo = listaGrupos->getGrupo(j);
                if (grupo->estudianteInscrito(idEstudiante)) {
                    cout << "Grupo " << grupo->getNumeroGrupo() << " - " << grupo->getCurso()->getNombre() << endl;
                }
            }
        }
    }
    else {
        cout << "Estudiante no encontrado." << endl;
    }
}

