#include "productoAlmacen.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

productoAlmacen::productoAlmacen(){
    this->id="NA";
    this->nombre="NA";
    this->precio=0.00;
    this->existencia=0;
}

productoAlmacen::productoAlmacen(string id, string nombre, string strprecio, string strexistencia){
    this->id=id;
    this->nombre=nombre;
    istringstream(strprecio) >> this->precio;
    istringstream(strexistencia) >> this->existencia;
}

int productoAlmacen::getExistencia(){
    return this->existencia;
}

string productoAlmacen::getID(){
    return this->id;
}

string productoAlmacen::getNombre(){
    return this->nombre;
}

float productoAlmacen::getPrecio(){
    return this->precio;
}

void productoAlmacen::imprime(){
    cout<<this->id<<','<<this->nombre<<','<<this->precio<<','<<this->existencia<<endl;
}

void productoAlmacen::restaExistencia(int comprado){
    this->existencia-=comprado;
}