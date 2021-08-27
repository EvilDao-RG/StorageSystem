#ifndef CARRITO_H
#define CARRITO_H

#include <string>
#include "productoCarrito.h"

using namespace std;

class Carrito{
    private:
        string cliente;
        productoCarrito productos[10];
        int size;
    public:
        Carrito(string cliente);
        void imprime();
        float total();
        void agregarProducto(productoCarrito producto);
        bool buscaID(string id);
        string getProdName(string id);
        float getProdPrice(string id);
        void cambiaCantidad(string id, int cantidad);
        void borrarProducto(string id);
        void vaciar();
        int getSize();
        int getProdCant(int posicion);
        string getProdID(int posicion);
};

#endif