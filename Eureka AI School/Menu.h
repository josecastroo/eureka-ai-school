#ifndef MENU_H
#define MENU_H
#include <iostream>
#include<sstream>
#include "ListaEstudiante.h"
#include "ListaProfe.h"
#include "ListaCursos.h"
#include "ListaGrupo.h"
#include "Horario.h"
#include "Matricula.h"
#include "PeriodoLectivo.h"
using namespace std;

class Menu {
private:
    ListaProfes* listaProfes;
    ListaEstudiantes* listaEstudiantes;
    ListaCursos* listaCursos;
    ListaGrupo* listaGrupo;
    PeriodoLectivo* periodoLectivo;
    Matricula* matricula;

public:
    Menu();
    ~Menu();
    void iniciar();
    void mostrarMenuPrincipal();
    void subMenuAdministracion();
    void subMenuMatricula();
    void subMenuBusquedasInformes();
};
#endif
