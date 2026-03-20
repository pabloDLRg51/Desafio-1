#include "tablero.h"
#include "piezas.h"
#include <iostream>
#include <cstdint>

using namespace std;

uint8_t **creacionTablero(int filas, int columnas) {
    /*Función que crea un tablero de forma dinamica, donde cada fila almacena
  columnas en bytes, es decir 8 bits cada columna. Inicialmente es llenada por
  ceros. Bit 0 representa un espacio vacio en el tablero y el bit 1 un espacio
  ocupado en el tablero.

  parametros:
  filas: numero de filas que el usuario haya ingresado para el tablero.
  columnas: numero de que el usuario haya ingresado para el tablero.

  retonar: un apuntador a apuntador que representa el tablero.*/

    int bytesPorFila = columnas / 8;
    uint8_t **tablero =
        new uint8_t *[filas]; /* Reserva de memoria para las filas*/
    for (int i=0;i<filas;i++) {
        tablero[i]=new uint8_t[bytesPorFila]; /* Reserva de memoria para los bytes de cada fila*/
        for (int j=0;j<bytesPorFila;j++) {
            tablero[i][j]=0; /* Inicializacion de bytes en 0*/
        }
    }
    return tablero;
}
void liberarMemoriaTablero(uint8_t **tablero, int filas) {
    /*Función que libera la memoria de cada fila del tablero y del tablero, para
  que no hayan fugas en la memoria.

  parametros:
  filas: numero de filas que el usuario haya ingresado para el tablero.
  uint8_t **tablero: apuntador a apuntador que representa el tablero.

  No devuelve ningun valor al finalizar su ejecución.*/

    for (int i=0;i<filas;i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
}
bool espacio(uint8_t **tablero, int fila, int columna) {
    /*funcion que verifica si una celda del tablero está libre. Esta funcion
  localiza el byte y bite que corresponde a la columna dentro del tablero.
  Utiliza una mascara con dezplazamiento para ubicar el espacio, para compprobar
  se usa un operador and para determinar si esa posicion esta ocupada o vacia.

  parametros:
  uint8_t **tablero: apuntador a apuntador que representa el tablero.
  fila: fila del espacio que se desea consultar
  columna: columna del espacio que se desea consultar

  retorno:
  true si el espacio esta libre (bit en 0)
  false si el espacio esta ocupado (Bit en 1)*/
    int byte=columna / 8;
    int bit=columna % 8;
    char mascara = 1 << bit;/*mascara para encontrar el bit*/
    if ((tablero[fila][byte] & mascara) == 0) { /*condicion que revisa el bit*/
        return true;
    }
    return false;
}

void imprimirTablero(uint8_t **tablero, int filas, int columnas,uint8_t* pieza, int filaPieza, int columnaPieza){
    /*Funcion que imprime el tablero con la pieza actual superpuesta. Recorre cada celda del tablero y muestra '#' si está ocupada (tanto en el tablero o la pieza) y '.' si está vacia.

    parametros:
    uint8_t **tablero: apuntador a apuntador que representa el tablero.
    int filas: numero de filas.
    int columnas: numero de columnas.
    uint8_t *pieza: arreglo que representa la pieza en formato 4x4 usando bits.
    int filaPieza: fila donde se posiciona la pieza en el tablero.
    int columnaPieza: columna donde se posiciona la pieza en el tablero.

    no retorna nada, solo muestra el tablero en pantalla.
    */
    //recorre cada fila del tablero
    for(int filaTablero=0;filaTablero<filas; filaTablero++){
        cout<<'|';
        //recorre cada columna del tablero
        for(int columnaTablero=0;columnaTablero<columnas;columnaTablero++){
            bool celdaOcupada=!espacio(tablero, filaTablero, columnaTablero);//verifica si la celda ta esta ocupada en el tablero
            bool piezaPresente=false;//indica si la pieza ocupa esta posicion
            //recorre la matriz 4x4 de la piezzza
            for(int filaLocal=0;filaLocal<4 && !piezaPresente;filaLocal++){
                for(int columnaLocal = 0; columnaLocal <4 && !piezaPresente;columnaLocal++){
                    //verifica si hay un bloque activo en la pieza
                    if (pieza[filaLocal] & (1 << columnaLocal)) {
                        //calcula la posicion en el tablero
                        int filaEnTablero=filaPieza +filaLocal;
                        int columnaEnTablero =columnaPieza+columnaLocal;
                        //Solo se dibuja si la pieza ya esta dentro del tablero
                        if ((filaEnTablero>=0)&&(filaEnTablero==filaTablero)&&(columnaEnTablero==columnaTablero)){
                            piezaPresente=true; //marca que la pieza ocupa la celda
                        }
                    }
                }
            }
            //si hay un bloque del tablero o de la pieza se imprime un numeral
            if(celdaOcupada || piezaPresente){
                cout << " # ";
            } else {
                cout << " . ";
            }
        }

        cout << "|\n";
    }
}

void encenderBit(uint8_t **tablero, int fila, int columna) {
    /*funcion que enciende un bit, o sea lo pone en 1 dependiendo de la fila y la
  columna. La funcion calcula que byte y que bit corresponden a la columna
  indicada y utiliza una mascara para encontrar el bit

  parametros:
  uint8_t **tablero: apuntador a apuntador que representa el tablero.
  fila: fila del espacio que se desea modificar
  columna: columna del espacio que se desea encender

  No retorna nada. Simplemente modifica el tablero*/
    int byte=columna / 8;
    int bit = columna % 8;
    uint8_t mascara= 1 << bit; //mascara para encontrar el bit y comparar
    tablero[fila][byte] = tablero[fila][byte] | mascara;//encender bit en la posicion indicada
}
void apagarBit(uint8_t**tablero, int fila, int columna){
    /*funcion que apaga un bit, o sea lo pone en 0 dependiendo de la fila y la
  columna. La funcion calcula que byte y que bit corresponden a la columna
  indicada y utiliza una mascara para encontrar el bit

  parametros:
  uint8_t **tablero: apuntador a apuntador que representa el tablero.
  fila: fila del espacio que se desea modificar
  columna: columna del espacio que se desea encender

  No retorna nada. Simplemente modifica el tablero*/
    int byte=columna/8;
    int bit=columna%8;
    uint8_t mascara=1<<bit;//mascara para encontrar el bit y comparar
    tablero[fila][byte]=tablero[fila][byte]&(~mascara);//apagar bit en la posicion indicada
}
bool filaLlena(uint8_t**tablero, int fila, int columnas){
    /*función que calcula si la fila esta llena, para que la fila este llena todas sus columnas
     deben estar en 1. 8 bits en 1, equivalen a 255 en base 10.

    parametros:
    uint8_t **tablero: apuntador a apuntador que representa el tablero.
    fila: indice de la fila del espacio que se desea comprobar
    columnas: numero de columnas que se desean comprobar

    return: returno un booleano, dependiendo si la fila esta llena o no.
     */
    int bytes=columnas/8;
    for(int i=0;i<bytes;i++){
        //si algun byte no esta completamente lleno o sea 255 en base decimal, la fila no esta llena.
        if(tablero[fila][i]!=255){
            return false;
        }
    }
    return true;
}
void eliminarFila(uint8_t**tablero, int fila, int columnas){
    /*
    Funcion que elimina una fila del tablero cuando está llena. en lugar de borrar la fila directamente, el algoritmo desplaza todas las filas superioresuna posicion hacia abajo y luego deja la fila superior vacia.

    parametros:
    uint8_t **tablero: apuntador a apuntador que representa el tablero.
    fila: indice de la fila del espacio que se desea eliminar
    columnas: numero de columnas que se desean comprobar

    no retorna nada, solo modifica el tablero.
    */

    int bytes=columnas/8;
    for(int i=fila;i>0;i--){ //desplaza todas las filas superiores una posicion abajo
        for(int j=0;j<bytes;j++){
            tablero[i][j]=tablero[i-1][j];
        }
    }
    for(int k=0;k<bytes;k++){
        tablero[0][k]=0;//se llena la fila 0 de ceros
    }
}
