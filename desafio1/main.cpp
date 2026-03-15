#include <iostream>
#include "validaciones.h"
#include "tablero.h"
using namespace std;

int main()
{
    int columnas;
    int filas;
    cout<<"ingrese el numero de largo (debe ser minimo 8): ";
    cin>>filas;
    cout<<"ingrese el numero de ancho (multiplo de 8 y debe ser minimo 8): ";
    cin>>columnas;
    validacionEntradaTablero(filas, columnas);
    unsigned char** tablero=creacionTablero(filas, columnas);
    int fila, columna;
    while(true){
        imprimirTablero(tablero, filas, columnas);
        cout<<"ingrese fila (si desea salir ingrese la fila -1): ";
        cin>>fila;
        if(fila==-1){
            break;
        }
        cout<<"Ingrese columna: ";
        cin>>columna;
        if(espacio(tablero, fila, columna)){
            encenderBit(tablero, fila, columna);
        }
        else{
            cout<<"Bloque en esta posición. "<<endl;
        }
    }
    liberarMemoriaTablero(tablero, filas);
    return 0;
}
