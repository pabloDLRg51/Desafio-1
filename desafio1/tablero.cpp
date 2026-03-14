#include <iostream>
#include "tablero.h"

using namespace std;

unsigned char** creacionTablero(int filas, int columnas){
/*Función que crea un tablero de forma dinamica, donde cada fila almacena columnas en bytes, es decir 8 bits cada columna. Inicialmente es llenada por ceros. Bit 0 representa un espacio vacio en el tablero y el bit 1 un espacio ocupado en el tablero.

parametros:
filas: numero de filas que el usuario haya ingresado para el tablero.
columnas: numero de que el usuario haya ingresado para el tablero.

retonar: un apuntador a apuntador que representa el tablero.*/

    int bytesPorFila=columnas/8;
    unsigned char** tablero=new unsigned char*[filas];/* Reserva de memoria para las filas*/
    for(int i=0;i<filas;i++){
        tablero[i]=new unsigned char[bytesPorFila];/* Reserva de memoria para los bytes de cada fila*/
        for(int j=0;j<bytesPorFila;j++){
            tablero[i][j]=0;/* Inicializacion de bytes en 0*/
        }
    }
    return tablero;
}
void liberarMemoriaTablero(unsigned char** tablero, int filas){
/*Función que libera la memoria de cada fila del tablero y del tablero, para que no hayan fugas en la memoria.

parametros:
filas: numero de filas que el usuario haya ingresado para el tablero.
unsigned char** tablero: un apuntador a apuntador que representa el tablero.

No devuelve ningun valor al finalizar su ejecución.*/

    for(int i=0;i<filas;i++){
        delete[] tablero[i];
    }
    delete[] tablero;
}
bool espacio(unsigned char** tablero, int fila, int columna){
/*funcion que verifica si una celda del tablero está libre. Esta funcion localiza el byte y bite que corresponde a la columna dentro del tablero. Utiliza una mascara con dezplazamiento para ubicar el espacio, para compprobar se usa un operador and para determinar si esa posicion esta ocupada o vacia.

parametros:
unsigned char** tablero: un apuntador a apuntador que representa el tablero.
fila: fila del espacio que se desea consultar
columna: columna del espacio que se desea consultar

retorno:
true si el espacio esta libre (bit en 0)
false si el espacio esta ocupado (Bit en 1)*/
    int byte=columna/8;
    int bit=columna%8;
    char mascara=1<<bit; /*mascara para encontrar el bit*/
    if((tablero[fila][byte]&mascara)==0){ /*condicion que revisa el bit*/
        return true;
    }
    return false;
}
void imprimirTablero(unsigned char** tablero, int filas, int columnas){
    for(int i=0;i<filas;i++){
        cout<<'|';
        for(int j=0;j<columnas;j++){
            if(espacio(tablero,i,j)){
                cout<<" . ";
            }
            else{
                cout<<" # ";
            }

        }
        cout<<'|'<<endl;
    }

}
void encenderBit(unsigned char** tablero,int fila, int columna){
/*funcion que enciende un bit, o sea lo pone en 1 dependiendo de la fila y la columna. La funcion calcula que byte y que bit corresponden a la columna indicada y utiliza una mascara para encontrar el bit

parametros:
unsigned char** tablero: un apuntador a apuntador que representa el tablero.
fila: fila del espacio que se desea modificar
columna: columna del espacio que se desea encender

No retorna nada. Simplemente modifica el tablero*/
    int byte=columna/8;
    int bit=columna%8;
    unsigned char mascara=1<<bit;
    tablero[fila][byte]=tablero[fila][byte]|mascara;
}

