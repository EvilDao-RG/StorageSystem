#include "Carrito.h"
#include "productoCarrito.cpp"


Carrito::Carrito(string cliente){
    this->cliente = cliente;
    this->size=0;
}

void Carrito::imprime(){
    for(int i=0;i<this->size;i++){
        this->productos[i].imprime();
    }
}

float Carrito::total(){
    float total;
    for (int i=0;i<this->size;i++){
        total+=this->productos[i].getPrecio()*this->productos[i].getCantidad();
    }
    return total;
}

void Carrito::agregarProducto(productoCarrito producto){
    this->productos[this->size]=producto;
    this->size++;
}

bool Carrito::buscaID(string id){
    for (int i=0;i<this->size;i++){
        if (this->productos[i].getID()==id){
            return true;
        }
    }
    return false;
}

string Carrito::getProdName(string id){
    for (int i=0;i<this->size;i++){
        if (this->productos[i].getID()==id){
            return this->productos[i].getNombre();
        }
    }
}

float Carrito::getProdPrice(string id){
    for (int i=0;i<this->size;i++){
        if (this->productos[i].getID()==id){
            return this->productos[i].getPrecio();
        }
    }
}

void Carrito::cambiaCantidad(string id, int cantidad){
    for (int i=0;i<this->size;i++){
        if (productos[i].getID()==id){
            this->productos[i].setCantidad(cantidad);
        }
    }
}

void Carrito::borrarProducto(string id){
    int buscado;
    for (int i=0;i<this->size;i++){
        if (productos[i].getID()==id){
            buscado=i;
        }
    }
    for (int h=buscado+1;h<this->size;h++){
        this->productos[h-1]=this->productos[h];
    }
    this->size-=1;
}

void Carrito::vaciar(){
    productoCarrito articulo;
    for (int i=0;i<size;i++){
        this->productos[i] = articulo;
    }
    this->size=0;
}

int Carrito::getSize(){
    return this->size;
}

int Carrito::getProdCant(int posicion){
    return this->productos[posicion].getCantidad();
}

string Carrito::getProdID(int posicion){
    return this->productos[posicion].getID();
}