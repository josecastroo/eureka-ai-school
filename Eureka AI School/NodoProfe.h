#ifndef NODOPROFE_H
#define NODOPROFE_H
#include "Profe.h"

class NodoProfe {
private:
    Profe* info;
    NodoProfe* sig;

public:
    NodoProfe(Profe*, NodoProfe*);
    ~NodoProfe();
    void setInfo(Profe*);
    Profe* getInfo();
    void setSiguiente(NodoProfe*);
    NodoProfe* getSiguiente();
    string toStringNodoProfe();
};
#endif
