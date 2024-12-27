#include "menu.h"

Menu::Menu() {
    listaProfes = new ListaProfes();
    listaEstudiantes = new ListaEstudiantes();
    listaCursos = new ListaCursos();
    listaGrupo = new ListaGrupo();
    periodoLectivo = new PeriodoLectivo();
    matricula = new Matricula(periodoLectivo);
}

Menu::~Menu() {
    delete listaProfes;
    delete listaEstudiantes;
    delete listaCursos;
    delete listaGrupo;
    delete periodoLectivo;
    delete matricula;
}

void Menu::iniciar() {
    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            subMenuAdministracion();
            break;
        case 2:
            subMenuMatricula();
            break;
        case 3:
            subMenuBusquedasInformes();
            break;
        case 4:
            listaProfes->guardarEnArchivo();
            listaProfes->cargarDesdeArchivo();
            listaEstudiantes->guardarEnArchivo();
            listaEstudiantes->cargarDesdeArchivo();
            listaCursos->guardarEnArchivo();
            listaCursos->cargarDesdeArchivo();
            listaGrupo->guardarEnArchivo();
            periodoLectivo->guardarEnArchivo();
            cout << "Datos guardados exitosamente.\n";
            break;
        case 5:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción invalida, intente nuevamente.\n";
        }
        system("pause");
        system("cls");
    } while (opcion != 5);
}

void Menu::mostrarMenuPrincipal() {
    cout << "\n\tMenu Principal\n\n";
    cout << "\t1. Submenu Administracion\n";
    cout << "\t2. Submenu Matricula\n";
    cout << "\t3. Submenu Busquedas e Informes\n";
    cout << "\t4. Guardar los Datos en Archivos\n";
    cout << "\t5. Salir\n\n";
    cout << "\tIngrese la opcion: ";
}

void Menu::subMenuAdministracion() {
    int opcion;
    do {
        cout << "\n\tSubmenu Administracion General\n\n";
        cout << "\t1. Ingresar Profesor\n";
        cout << "\t2. Ingresar Estudiante\n";
        cout << "\t3. Ingresar Bloque o Periodo\n";
        cout << "\t4. Ingresar Curso\n";
        cout << "\t5. Ingresar Grupo\n";
        cout << "\t6. Asignar Profesor a Grupo\n";
        cout << "\t0. Regresar al Menu Principal\n\n";
        cout << "\tIngrese la opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1: {
            string nombre, id, telefono, email, grado;
            cout << "\t\nIngrese los datos del profesor:\n";
            cout << "\tNombre: "; cin >> nombre;
            cout << "\tID: "; cin >> id;
            cout << "\tTelefono: "; cin >> telefono;
            cout << "\tEmail: "; cin >> email;
            cout << "\tGrado Academico: "; cin >> grado;
            listaProfes->agregarInicio(new Profe(nombre, id, telefono, email, grado));
            cout << "\tProfesor agregado exitosamente.\n";
            break;
        }
        case 2: {
            string nombre, id, especialidad, telefono, email;
            cout << "\n\tIngrese los datos del estudiante:\n";
            cout << "\tNombre: "; cin >> nombre;
            cout << "\tID: "; cin >> id;
            cout << "\tEspecialidad: "; cin >> especialidad;
            cout << "\tTelefono: "; cin >> telefono;
            cout << "\tEmail: "; cin >> email;
            listaEstudiantes->insertarInicio(new Estudiantes(nombre, id, especialidad, telefono, email));
            cout << "\tEstudiante agregado exitosamente.\n";
            break;
        }
        case 3: {
            int numeroPeriodo;
            int numeroGrupo;
            cout << "\t\nIngrese el numero del periodo (1-4): \n\n";
            cout << "\t1. Enero a marzo\n ";
            cout << "\t2. Abril a Junio\n ";
            cout << "\t3. Julio a Setiembre\n ";
            cout << "\t4. Octubre a Diciembre\n ";
            cin >> numeroPeriodo;


            if (numeroPeriodo < 1 || numeroPeriodo > 4) {
                cout << "Numero de periodo invalido. Debe ser entre 1 y 4.\n";
                break;
            }

            cout << "Ingrese el numero de grupo a asignar al periodo: ";
            cin >> numeroGrupo;

            // Buscar el grupo con el número dado
            Grupo* grupo = listaGrupo->buscarGrupo(numeroGrupo);

            if (!grupo) {
                cout << "Grupo no encontrado.\n";
            }
            else {

                switch (numeroPeriodo) {
                case 1:
                    periodoLectivo->agregarGrupoPeriodo1(grupo);
                    cout << "Grupo asignado al Periodo 1 exitosamente.\n";
                    break;
                case 2:
                    periodoLectivo->agregarGrupoPeriodo2(grupo);
                    cout << "Grupo asignado al Periodo 2 exitosamente.\n";
                    break;
                case 3:
                    periodoLectivo->agregarGrupoPeriodo3(grupo);
                    cout << "Grupo asignado al Periodo 3 exitosamente.\n";
                    break;
                case 4:
                    periodoLectivo->agregarGrupoPeriodo4(grupo);
                    cout << "Grupo asignado al Periodo 4 exitosamente.\n";
                    break;
                }
            }
            break;
        }
        case 4: {
            string nombre, id, horas, estado;
            string horaInicio, horaFin, diasSemanales;
            int precio;
            cout << "\n\tIngrese los datos del curso:\n";
            cout << "\tNombre: "; cin >> nombre;
            cout << "\tID: "; cin >> id;
            cout << "\tHoras: "; cin >> horas;
            cout << "\tPrecio: "; cin >> precio;
            cout << "\tEstado (Disponible/No Disponible): "; cin >> estado;
            cout << "\t\nIngrese los datos del horario para el curso\n";
            cout << "\tHora de inicio (HH:MM): "; cin >> horaInicio;
            cout << "\tHora de finalizacion (HH:MM): "; cin >> horaFin;
            cout << "\tDias semanales: ";
            cin.ignore();
            getline(cin, diasSemanales);
            Horario* horario = new Horario(horaInicio, horaFin, diasSemanales);
            listaCursos->agregarInicio(new Curso(nombre, id, horas, precio, estado, horario));
            cout << "Curso agregado exitosamente.\n";
            break;
        }
        case 5: {
            string idCurso;
            int numeroGrupo;
            int capacidadMax;

            cout << "\n\tIngrese el ID del curso para el grupo: ";
            cin >> idCurso;

            // Buscar el curso en la lista de cursos
            Curso* curso = listaCursos->buscarCurso(idCurso);

            if (!curso) {
                cout << "Curso no encontrado. Asegurese de ingresar un ID valido.\n";
            }
            else {
                cout << "\n\tIngrese el numero del grupo: ";
                cin >> numeroGrupo;

                cout << "\n\tIngrese la capacidad maxima del grupo: ";
                cin >> capacidadMax;

                // Crear el nuevo grupo y asignar el curso
                Grupo* nuevoGrupo = new Grupo();
                nuevoGrupo->setNumeroGrupo(numeroGrupo);
                nuevoGrupo->setCapacidadMax(capacidadMax);
                nuevoGrupo->setCurso(curso);

                // Insertar el grupo en la lista de grupos
                listaGrupo->insertarInicio(nuevoGrupo);

                cout << "Grupo creado y asignado al curso exitosamente.\n";
            }
            break;
        }
        case 6: {
            string idProfesor;
            int numeroGrupo;

            cout << "\n\tIngrese el ID del profesor: ";
            cin >> idProfesor;


            Profe* profesor = listaProfes->buscarProfe(idProfesor);

            if (!profesor) {
                cout << "Profesor no encontrado. Asegurese de ingresar un ID valido.\n";
            }
            else {
                cout << "\n\tIngrese el numero de grupo al que desea asignar el profesor: ";
                cin >> numeroGrupo;


                Grupo* grupo = listaGrupo->buscarGrupo(numeroGrupo);

                if (!grupo) {
                    cout << "Grupo no encontrado. Asegúrese de ingresar un numero de grupo valido.\n";
                }
                else {

                    grupo->setProfesor(profesor);
                    cout << "Profesor asignado exitosamente al grupo.\n";
                }
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Opción invalida.\n";
        }
        system("pause");
        system("cls");
    } while (opcion != 0);
}

void Menu::subMenuMatricula() {
    int opcion;
    do {
        cout << "\n\tSubmenu Matricula\n\n";
        cout << "\t1. Matricular Estudiante\n";
        cout << "\t2. Desmatricular Estudiante\n";
        cout << "\t0. Regresar al Menu Principal\n\n";
        cout << "\tIngrese la opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1: {
            string idEstudiante;
            int grupoNum;
            cout << "\n\tID del estudiante: "; cin >> idEstudiante;
            cout << "\tNumero de grupo: "; cin >> grupoNum;
            Estudiantes* estudiante = listaEstudiantes->buscarEstudiante(idEstudiante);
            Grupo* grupo = listaGrupo->buscarGrupo(grupoNum);
            if (estudiante && grupo) {
                matricula->matricularEstudiante(estudiante, grupo);
            }
            else {
                cout << "Estudiante o grupo no encontrado.\n";
            }
            break;
        }
        case 2: {
            string idEstudiante;
            int grupoNum;
            cout << "\n\tID del estudiante: "; cin >> idEstudiante;
            cout << "\tNumero de grupo: "; cin >> grupoNum;
            Estudiantes* estudiante = listaEstudiantes->buscarEstudiante(idEstudiante);
            Grupo* grupo = listaGrupo->buscarGrupo(grupoNum);
            if (estudiante && grupo) {
                matricula->desmatricularEstudiante(estudiante, grupo);
            }
            else {
                cout << "Estudiante o grupo no encontrado.\n";
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Opcion invalida.\n";
        }
        system("pause");
        system("cls");
    } while (opcion != 0);
}

void Menu::subMenuBusquedasInformes() {
    int opcion;
    do {
        cout << "\n\tBusquedas e Informes\n\n";
        cout << "\t1. Informe Profesores Registrados\n";
        cout << "\t2. Informe Estudiantes Registrados\n";
        cout << "\t3. Informe Cursos Matriculados por un Estudiante\n";
        cout << "\t4. Informe Profesor Especifico\n";
        cout << "\t5. Informe Periodos Habilitados para el Annio\n";
        cout << "\t6. Informe Grupo Especifico\n";
        cout << "\t0. Regresar al Menu Principal\n\n";
        cout << "\tIngrese la opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            cout << "\n\tInforme de Profesores:\n";
            cout << listaProfes->toStringProfes();
            break;
        case 2:
            cout << "\n\tInforme de Estudiantes:\n";
            cout << listaEstudiantes->toString();
            break;
        case 3: {
            string idEstudiante;
            cout << "\n\tID del estudiante: "; cin >> idEstudiante;
            matricula->buscarEstudianteYListarGrupos(idEstudiante);
            break;
        }
        case 4: {
            string idProfesor;
            cout << "\n\tID del profesor: "; cin >> idProfesor;
            Profe* profesor = listaProfes->buscarProfe(idProfesor);
            if (profesor) {
                cout << profesor->toString();
            }
            else {
                cout << "Profesor no encontrado.\n";
            }
            break;
        }
        case 5:
            cout << "\n\tLista de periodos habilitados:\n";
            cout << periodoLectivo->toStringPeriodo1();
            cout << periodoLectivo->toStringPeriodo2();
            cout << periodoLectivo->toStringPeriodo3();
            cout << periodoLectivo->toStringPeriodo4();
            break;
        case 6: {
            int numeroGrupo;
            cout << "Numero de grupo: "; cin >> numeroGrupo;
            Grupo* grupo = listaGrupo->buscarGrupo(numeroGrupo);
            if (grupo) {
                cout << grupo->toString();
            }
            else {
                cout << "Grupo no encontrado.\n";
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Opcion invalida.\n";
        }
        system("pause");
        system("cls");
    } while (opcion != 0);
}
