#include <string>

#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H

using namespace std;

class productoCarrito{
    private:
        string id;
        string nombre;
        float precio;
        int cantidad;
    public:
        productoCarrito();
        productoCarrito(string id, string nombre, float precio, int cantidad);
        float getPrecio();
        int getCantidad();
        string getID();
        string getNombre();
        void imprime();
        void setCantidad(int cantidad);
};

#endif