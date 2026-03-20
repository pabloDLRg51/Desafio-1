#include <cstdint>
#include "piezas.h"
#include "tablero.h"
#include <iostream>
using namespace std;
int anchoPieza(uint8_t pieza[]){
/*funcion que calcula el ancho de una pieza representada en formato 4x4 usando btis recorre la pieza y determina la columna más a la derecha que está ocupada, retornando el ancho real de la pieza.

parametros:
uint8_t pieza[]:arreglo que representa la pieza en formato de bits.

retorna:
int:ancho de la pieza (numero de columnas ocupadas).
 */
    int ancho = 0;

    for(int fila = 0; fila < 4; fila++){
        for(int columna = 0; columna < 4; columna++){

            if(pieza[fila] & (1 << columna)){
                if(columna > ancho)
                    ancho = columna;
            }
        }
    }

    return ancho + 1;
}
bool colision(uint8_t **tablero, uint8_t pieza[], int alto, int ancho,int filaPieza, int columnaPieza){
/*Funcion que revisa si una pieza colisiona con el tablero.
Basicamente recorra la piea y por cada bloque activa verifica dos cosas:
1. Si se sale de los limites del tablero.
2. Si choca con alguna posicion ya ocupada en el tablero.
si pasa alguna de estas cosas, hay colision

parametros:
uint8_t **tablero: puntero a puntero que representa el tablero
uint8_t pieza[]: pieza en formato 4x4 usando bits.
int alto: numero de filas del tablero
int ancho: numero de columnas de tablero
int filaPieza:  fila donde se quiere ubicar la pieza
int colummnaPieza: colummna donde se quiere ubicar la pieza

retorna
un booleano si hay colision retorna true, false si no.

*/
    for(int filas=0;filas<4;filas++) {
        for(int columnas=0;columnas<4;columnas++){
            if(pieza[filas]&(1 << columnas)){
                int filaTablero= filaPieza + filas;
                int columnaTablero= columnaPieza + columnas;
                if((columnaTablero<0)||(filaTablero>=alto)||(columnaTablero>=ancho)){
                    return true;
                }
                if(filaTablero<0){
                    continue;
                }
                if(filaTablero>=0){
                    int byteIndex=columnaTablero / 8;
                    int bitIndex=columnaTablero % 8;
                    if(tablero[filaTablero][byteIndex]&(1 << bitIndex)){
                        return true;
                    }
                }

            }
        }
    }
    return false;
}

bool moverIzquierda(uint8_t**tablero, uint8_t* pieza, int alto, int ancho, int fila, int& columna){
/*Funcion que mueve la posicion una posición hacia a la izquierda, revisa si al moverse a la izquierda hay colision, si no hay colision, actualiza la columna y mueve la pieza. si hay colision, no hace nada.

parametros:
uint8_t **tablero: puntero a puntero que representa el tablero
uint8_t *pieza: pieza actual en formato 4x4 usando bits
int alto: numero de filas del tablero
int ancho: numero de columnas de tablero
int fila: fila acutal de la pieza
int &columna: columna actual de la pieza, si se mueve se modifica

retorna:
un booleano si la pieza se movio retorna true, false si no.
 */
    if(!colision(tablero,pieza,alto,ancho,fila, columna-1)){
        columna--;
        return true;
    }
    return false;
}
bool moverDerecha(uint8_t**tablero, uint8_t* pieza, int alto, int ancho, int fila, int& columna){
    /*Funcion que mueve la posicion una posición hacia a la derecja, revisa si al moverse a la derecha hay colision, si no hay colision, actualiza la columna y mueve la pieza. si hay colision, no hace nada.

parametros:
uint8_t **tablero: puntero a puntero que representa el tablero
uint8_t *pieza: pieza actual en formato 4x4 usando bits
int alto: numero de filas del tablero
int ancho: numero de columnas de tablero
int fila: fila acutal de la pieza
int &columna: columna actual de la pieza, si se mueve se modifica

retorna:
un booleano si la pieza se movio retorna true, false si no.
 */
    if(!colision(tablero,pieza,alto,ancho,fila, columna+1)){
        columna++;
        return true;
    }
    return false;
}
bool bajar(uint8_t** tablero, uint8_t* pieza,int alto, int ancho,int& fila, int columna){
/*
 Funcion que baja la pieza una posicion hacia abajo. Revisa si al mover la pieza una fila abajo hay colision, si no hay colision, actualiza la fila y la pieza baja. Si hay colision, no se mueve.

parametros:
uint8_t **tablero: puntero a puntero que representa el tablero
uint8_t *pieza: pieza actual en formato 4x4 usando bits
int alto: numero de filas del tablero
int ancho: numero de columnas de tablero
int &fila: fila acutal de la pieza, si se mueve se modifica
int columna: columna actual de la pieza

retorna:
un booleano si la pieza se movio retorna true, false si no.
*/
    if(!colision(tablero, pieza, alto, ancho, fila + 1, columna)){
        fila++;
        return true;
    }
    return false;
}
bool puedeBajar(uint8_t** tablero, uint8_t* pieza,int alto, int ancho,int fila, int columna){
/*Funcion que verifica si la pieza puede bajar una posicion. Revisa si al mover la pieza una fila hacia abajo hay colision. No modifica la posicion, solo hace la comprobacion.

parametros:
uint8_t **tablero: puntero a puntero que representa el tablero
uint8_t *pieza: pieza actual en formato 4x4 usando bits
int alto: numero de filas del tablero
int ancho: numero de columnas de tablero
int fila: fila acutal de la pieza
int columna: columna actual de la pieza

retorna:
booleano true si puede bajar, false si no.
*/
    // si no hay colisión una fila más abajo, puede bajar
    return !colision(tablero, pieza, alto, ancho, fila + 1, columna);
}
void rotar(uint8_t** tablero, uint8_t* pieza, int alto, int ancho, int fila, int columna){
    rotacion(pieza);
    if(colision(tablero, pieza, alto, ancho, fila, columna)){
        rotacion(pieza);
        rotacion(pieza);
        rotacion(pieza);
    }
}
void fijarPieza(uint8_t** tablero, uint8_t* pieza,int fila, int columna){
/*Funcion que fija la pieza en el tablero. Recorre la pieza y por cada bloque activo, enciende el bit correspondiente en el trablero. Es decir, la pieza pasa de ser movible a quedar guardada en el tablero

parametros:
uint8_t **tablero: puntero a puntero que representa el tablero
uint8_t *pieza: pieza actual en formato 4x4 usando bits
int fila: fila donde esta posicionada la pieza.
int columna: columna donde esta posicionada la pieza

no retorna nada
*/
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(pieza[i]&(1<<j)){
                int filaTablero=fila+i;
                int columnaTablero=columna+j;
                if((filaTablero>=0)&&(columnaTablero>=0)){
                    encenderBit(tablero, filaTablero,columnaTablero);
                }

            }
        }
    }
}
uint8_t* nuevaPieza(int anchoTablero, int& fila, int& columna){
/*
 Funcion que genera una nueva pieza y la posiciona en el tablero, crea una pieza aleatoria, la ubica en la parte superior del tablero (fila 0) y la centra horizontalmente segun su ancho.

parametros:
int anchoTablero: numero de columnas del tablero.
int& fila: fila donde aparecera la pieza.
int& columna: columna donde aparecera la pieza.

retorna:
uint8_t* pieza: puntero a la nueva pieza generada.

*/
    uint8_t* pieza=piezaAleatoria();
    int filaMinima, filaMaxima, columnaMinima, columnaMaxima;
    obtenerLimitesrotacion(pieza, filaMinima, filaMaxima, columnaMinima, columnaMaxima);
    int altura=filaMaxima-filaMinima+1;
    fila=-(altura/2);
    columna=(anchoTablero-anchoPieza(pieza))/2;
    return pieza;
}
bool procesarMovimiento(uint8_t** tablero, uint8_t* pieza,int alto, int ancho,int& fila, int& columna,char accion,bool& movimientoHorizontalUsado){
    /*
Procesa la accion ingresada por el usuario y actualiza la posicion de la pieza. Permite mover a la izquierda, derecha, bajar o rotar. Controla que solo se pueda realizar un movimiento horizontal por turno.

parametros:
uint8_t** tablero: apuntador a apuntador que representa el tablero
uint8_t* pieza: pieza actual en formato 4x4
int alto: numero de filas del tablero
int ancho: numero de columnas del tablero
int& fila: posicion vertical de la pieza
int& columna: posicion horizontal de la pieza
char accion: accion ingresada por el usuario
bool& movimientoHorizontalUsado: indica si ya se hizo un movimiento horizontal

retorna:
bool: true si la pieza debe fijarse en el tablero, false si no
*/
    switch(accion){
    case 'a':
        if(!movimientoHorizontalUsado){
            moverIzquierda(tablero,pieza,alto,ancho,fila,columna);
            movimientoHorizontalUsado=true;
        }
        break;
    case 'd':
        if(!movimientoHorizontalUsado){
            moverDerecha(tablero,pieza,alto,ancho,fila,columna);
            movimientoHorizontalUsado=true;
        }
        break;
    case 's':
        if(bajar(tablero,pieza,alto,ancho,fila,columna)){
            movimientoHorizontalUsado=false;
            if(!puedeBajar(tablero,pieza,alto,ancho,fila,columna)){
                return true;
            }
        } else {
            return true;
        }
        break;
    case 'w':
        rotar(tablero, pieza, alto, ancho, fila, columna);
        break;
    default:
        cout << "Ingrese una opcion valida." << endl;
        break;
    }
    return false;
}
