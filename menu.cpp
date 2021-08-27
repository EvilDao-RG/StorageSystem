#include "Almacen.cpp"
#include "Carrito.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void verProductos(Almacen& bodega){
    //Desplegar productos del almacen
    bodega.imprime();
}

void comprar(Almacen& bodega,Carrito& compras){
    //Valores a utilizar
    string id,
           confirmacion,
           strcantidad;
    bool compra;
    int cantidad;
    do{
        //Pedir id y cantidad
        cout<<"\nIngrese el ID del producto que desea comprar"<<endl;
        cin>>id;
        cout<<"Ingrese la cantidad de articulos que desea comprar"<<endl;
        cin>>strcantidad;
        cout<<strcantidad<<" articulos del producto "<<id<<"\nConfirme (Si/No)"<<endl;
        cin>>confirmacion;
        //Verificar confirmacion
        if (confirmacion=="Si" or confirmacion=="si" or confirmacion=="SI" or confirmacion=="sI"){
            //Verificar id
            if (bodega.buscaID(id)==true){
                //Verificar que la cantidad introducida es un entero
                if (istringstream(strcantidad)>>cantidad){
                    //Verificar existencia
                    if (bodega.checkStock(id,cantidad)==true){
                        //Agregar producto a carrito
                        productoCarrito producto(id,bodega.getProdName(id),bodega.getProdPrice(id),cantidad);
                        compras.agregarProducto(producto);
                        compra=true;
                    } else{
                        cout<<"No hay suficiente stock en el almacen"<<endl;
                        compra=false;
                    }
                } else{
                    cout<<"Introduzca un numero entero"<<endl;
                    compra=false;
                }               
            } else{
                cout<<"No se encontro el producto. Ingrese un ID valido"<<endl;
                compra=false;
            }
        } else if(confirmacion=="No" or confirmacion=="no" or confirmacion=="NO" or confirmacion=="nO"){
        } else{
            cout<<"Confirmacion no valida"<<endl;
        } 
} while(compra!=true);
}

void verCarrito(Carrito& compras, string cliente){
    //Desplegar encabezado con nombre
    cout<<"Carrito de compras de "<<cliente<<"\n"<<endl;
    //Desplegar productos del carrito
    compras.imprime();
}

void editar(Almacen& bodega, Carrito& compras){
    //Variables
    string id,
           confirmacion,
           opcion,
           strcantidad;
    int cantidad;
    bool edit;
    do{
        //Pedir opcion
        cout<<"\nQue desea hacer?"<<endl;
        cout<<"1- Borrar"<<endl;
        cout<<"2- Cambiar cantidad"<<endl;
        cin>>opcion; 
        if(opcion=="1"){
            //Pedir id
            cout<<"\nIngrese el ID del producto que quiere borrar"<<endl;
            cin>>id;
            //Pedir confirmacion
            cout<<"Borrar "<<id<<" del carrito\nConfirme(Si/No)"<<endl;
            cin>>confirmacion;
            //Verificar confirmacion
            if (confirmacion=="Si" or confirmacion=="si" or confirmacion=="SI" or confirmacion=="sI"){
                //Verificar ID
                if (compras.buscaID(id)==true){
                    //Borrar producto
                    compras.borrarProducto(id);
                    edit=true;
                } else{
                    cout<<"No se encontro el producto. Ingrese un ID valido"<<endl;
                    edit=false;
                }
            } else if(confirmacion=="No" or confirmacion=="no" or confirmacion=="NO" or confirmacion=="nO"){
                edit=false;
            } else{
                cout<<"Confirmacion no valida"<<endl;
            }
        }else if(opcion=="2"){
            //Pedir id
            cout<<"\nIngrese el ID del producto que quiere editar"<<endl;
            cin>>id;
            //Pedir cantidad
            cout<<"Cuantos articulos quiere comprar?"<<endl;
            cin>>strcantidad;
            //Pedir confirmacion
            cout<<strcantidad<<" articulo(s) del producto "<<id<<"\nConfirme (Si/No)"<<endl;
            cin>>confirmacion;
            //Verificar confirmacion
            if (confirmacion=="Si" or confirmacion=="si" or confirmacion=="SI" or confirmacion=="sI"){
                //Verificar ID
                if (compras.buscaID(id)==true){
                    //Verificar que la cantidad introducida es un entero
                    if(istringstream(strcantidad)>>cantidad){
                        //Verificar existencia
                        if (bodega.checkStock(id,cantidad)==true){
                           //Editar carrito
                            compras.cambiaCantidad(id,cantidad);
                            edit=true;
                        } else{
                            cout<<"No hay suficiente stock en el almacen"<<endl;
                            edit=false;
                        }
                    }else{
                        cout<<"Introduzca un numero entero"<<endl;
                        edit=false;
                    }
                }else{
                    cout<<"No se encontro el producto. Ingrese un ID valido"<<endl;
                    edit=false;
                } 
            }else if(confirmacion=="No" or confirmacion=="no" or confirmacion=="NO" or confirmacion=="nO"){
                edit=false;
            } else{
                cout<<"Confirmacion no valida"<<endl;
            } 
        }else{
            cout<<"Por favor, seleccione una opcion valida"<<endl;
        }
    } while(edit!=true);
}

void pagar(Carrito& compras, Almacen& bodega){
    if(compras.getSize()==0){
        cout<<"El carrito esta vacio"<<endl;
        cout<<"Para pagar, agregue productos a su carrito"<<endl;
    }else{
        //Desplegar total
        cout<<"Se ha cargado la cantidad de $"<<compras.total()<<" a su cuenta"<<endl;
        cout<<"Disfrute sus productos"<<endl;
        //Descontar existencia
        for (int i=0;i<compras.getSize();i++){
            bodega.restaProducto(compras.getProdCant(i),compras.getProdID(i));
        }
        //Vaciar carrito
        compras.vaciar();
    }
}

void salir(string name){
    //Desplegar despedida con nombre del cliente
    cout<<"Que tenga un excelente dia "<<name<<"!"<<endl;
}

int main(){
    //Variables a utilizar
    string cliente,
           linea,
           nombre,
           id,
           precio,
           existencia,
           opcion;
    //Creacion de almacen
    Almacen bodega;
    //Leer archivo
    ifstream lector("productos.txt");
    while(!lector.eof()){
        getline(lector,linea);
        stringstream ss(linea);
        for(int i=0; i<4; i++){
            if (i==0){
                getline(ss,id,',');
            } else if (i==1){
                getline(ss,nombre,',');
            } else if (i==2){
                getline(ss,precio,',');
            } else if (i==3){
                getline(ss,existencia,',');
            }
        }
        //Declarar producto y agregar a almacen
        productoAlmacen articulo(id, nombre, precio, existencia);
        bodega.agregarProducto(articulo);
    }
    lector.close();
    //Bienvenida
    cout<<"Bienvenido al portal de Tienda"<<endl;
    cout<<"Cual es su nombre?"<<endl;
    cin>>cliente;
    cout<<"\nBuen dia "<<cliente<<endl;
    //Creacion de carrito
    Carrito compras(cliente);
    //Menú
    do{
        cout<<"\n=========================="<<endl;
        cout<<" Seleccione una opcion"<<endl;
        cout<<"  1) Ver productos"<<endl; 
        cout<<"  2) Comprar"<<endl;
        cout<<"  3) Ver carrito"<<endl;
        cout<<"  4) Editar"<<endl;
        cout<<"  5) Pagar"<<endl;
        cout<<"  6) Salir\n"<<endl;
        cin>>opcion;
        cout<<"\n";
        //Opciones
        if(opcion=="1"){
            verProductos(bodega);
        } else if(opcion=="2"){
            comprar(bodega,compras);
        } else if(opcion=="3"){
            verCarrito(compras,cliente);
        } else if(opcion=="4"){
            editar(bodega,compras);
        } else if(opcion=="5"){
            pagar(compras,bodega);
        } else if(opcion=="6"){
            salir(cliente);
        } else{
            cout<<"Por favor, seleccione una opcion valida"<<endl;
        }
    } while (opcion!="6");
}