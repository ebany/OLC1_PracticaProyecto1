#ifndef NODO_H
#define NODO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QString>
#include <QList>


using namespace std;


class Nodo{
    public:
        
        string token;
        string lexema;
        int fila;
        int columna;
        QList<Nodo*> hijos;
        int nHijos;
        //Nodo *hijos[15];        
        
        Nodo(string token, string lexema, int fila, int columna){
            this->token = token;
            this->lexema = lexema;
            this->fila = fila;
            this->columna = columna;
            this->nHijos = 0;
        }

        void addHijo(Nodo *hijo){
            this->hijos.append(hijo);
            //this->hijos[this->nHijos] = hijo;
            this->nHijos++;
        }
};

#endif // NODO_H
