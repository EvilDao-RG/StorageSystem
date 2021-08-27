#ifndef ALMACEN_H
#define ALMACEN_H


#include "productoAlmacen.h"
using namespace std;

class Almacen{
    private:
        productoAlmacen productos[20];
        int size;
    public:
        Almacen();
        void imprime();
        void agregarProducto(productoAlmacen producto);
        bool buscaID(string id);
        bool checkStock(string id, int cantidad);
        string getProdName(string id);
        float getProdPrice(string id);
        void restaProducto(int comprado, string id);
};

#endif