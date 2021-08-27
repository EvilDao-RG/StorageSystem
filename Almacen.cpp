#include "productoAlmacen.cpp"
#include "Almacen.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Almacen::Almacen(){
    this->size=0;
}

void Almacen::agregarProducto(productoAlmacen producto){
    this->productos[this->size]=producto;
    this->size+=1;
}

void Almacen::imprime(){
    cout<<"Estos son nuestros productos!\n"<<endl;
    cout<<"ID,Nombre,Precio,Existencia"<<endl;
    for(int i=0;i<this->size;i++){
        this->productos[i].imprime();
    }
}

bool Almacen::buscaID(string id){
    for (int i=0;i<this->size;i++){
        if (productos[i].getID()==id){
            return true;
        }
    }
    return false;
}

bool Almacen::checkStock(string id, int cantidad){
    for (int i=0;i<this->size;i++){
        if (productos[i].getID()==id){
            if ((productos[i].getExistencia()-cantidad)>=0){
                return true;
            } else{
                return false;
            }
        } 
    }
}

string Almacen::getProdName(string id){
    for (int i=0;i<this->size;i++){
        if (productos[i].getID()==id){
            return productos[i].getNombre();
        }
    }
}

float Almacen::getProdPrice(string id){
    for (int i=0;i<this->size;i++){
        if (productos[i].getID()==id){
            return productos[i].getPrecio();
        }
    }
}

void Almacen::restaProducto(int comprado, string id){
    for (int i=0;i<this->size;i++){
        if (productos[i].getID()==id){
            productos[i].restaExistencia(comprado);
        }
    }
}