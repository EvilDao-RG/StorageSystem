#include "productoCarrito.h"
#include <iostream>
#include <string>

using namespace std;

productoCarrito::productoCarrito(){
    this->id="NA";
    this->nombre="NA";
    this->precio=0.00;
    this->cantidad=0;
}

productoCarrito::productoCarrito(string id, string nombre, float precio, int cantidad){
    this->id=id;
    this->nombre=nombre;
    this->precio=precio;
    this->cantidad=cantidad;
}

float productoCarrito::getPrecio(){
    return this->precio;
}

int productoCarrito::getCantidad(){
    return this->cantidad;
}

void productoCarrito::imprime(){
    cout<<this->id<<','<<this->nombre<<','<<this->precio<<','<<this->cantidad<<endl;
}

string productoCarrito::getID(){
    return this->id;
}

string productoCarrito::getNombre(){
    return this->nombre;
}

void productoCarrito::setCantidad(int cantidad){
    this->cantidad=cantidad;
}