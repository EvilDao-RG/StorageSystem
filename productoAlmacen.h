#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H

#include <string>
using namespace std;

class productoAlmacen{
    private:
        string id;
        string nombre;
        float precio;
        int existencia;
    public:
        productoAlmacen();
        productoAlmacen(string id, string nombre, string strprecio, string strexistencia);
        void imprime();
        string getID();
        int getExistencia();
        string getNombre();
        float getPrecio();
        void restaExistencia(int comprado);
    };

#endif