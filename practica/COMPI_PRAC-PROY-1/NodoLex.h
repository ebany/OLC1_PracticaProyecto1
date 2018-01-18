#ifndef NODOLEX_H
#define NODOLEX_H
#include <iostream>
#include <string>
#include <QList>

using namespace std;

class ErrLex
{
public:    
    string error;
    int columna;
    int fila;
    string archivo = "";
    ErrLex(string error_,int columna_,int fila_):error(error_)
      ,columna(columna_),fila(fila_){}
};

class Gnrc{
public:
    string tipo;
    string id;
    QList< Gnrc*> parametros;
    string visibilidad = "+";
    int fila;
};

class InfoCls{
public:
    string visibilidad = "+";
    string id;
    string extendss;
    QList<Gnrc*> metodos;
    QList<Gnrc*> funciones;
    QList<Gnrc*> atributos;
    QList<Gnrc*> constructores;
    QList<Gnrc*> overrides;
    int fila;
};

#endif // NODOLEX_H
