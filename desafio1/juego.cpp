#include <cstdint>
#include "piezas.h"
#include "tablero.h"
#include <iostream>
using namespace std;
int anchoPieza(uint8_t pieza[]){

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

    for(int filas=0;filas<4;filas++) {
        for(int columnas=0;columnas<4;columnas++){
            if(pieza[filas]&(1 << columnas)){
                int filaTablero= filaPieza + filas;
                int columnaTablero= columnaPieza + columnas;
                if(filaTablero<0||columnaTablero<0||filaTablero >= alto || columnaTablero >= ancho){
                    return true;
                }
                int byteIndex=columnaTablero / 8;
                int bitIndex=columnaTablero % 8;
                if(tablero[filaTablero][byteIndex]&(1 << bitIndex)){
                    return true;
                }
            }
        }
    }
    return false;
}

bool moverIzquierda(uint8_t**tablero, uint8_t* pieza, int alto, int ancho, int fila, int& columna){
    if(!colision(tablero,pieza,alto,ancho,fila, columna-1)){
        columna--;
        return true;
    }
    return false;
}
bool moverDerecha(uint8_t**tablero, uint8_t* pieza, int alto, int ancho, int fila, int& columna){
    if(!colision(tablero,pieza,alto,ancho,fila, columna+1)){
        columna++;
        return true;
    }
    return false;
}
bool bajar(uint8_t** tablero, uint8_t* pieza,int alto, int ancho,int& fila, int columna){
    if(!colision(tablero, pieza, alto, ancho, fila + 1, columna)){
        fila++;
        return true;
    }
    return false;
}
bool puedeBajar(uint8_t** tablero, uint8_t* pieza,int alto, int ancho,int fila, int columna){

    // si no hay colisión una fila más abajo, puede bajar
    return !colision(tablero, pieza, alto, ancho, fila + 1, columna);
}
void rotar(uint8_t** tablero, uint8_t* pieza, int alto, int ancho, int fila, int columna){
    rotacionesHorarias(pieza);
    if(colision(tablero, pieza, alto, ancho, fila, columna)){
        rotacionesHorarias(pieza);
        rotacionesHorarias(pieza);
        rotacionesHorarias(pieza);
    }
}
void fijarPieza(uint8_t** tablero, uint8_t* pieza,int fila, int columna){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(pieza[i]&(1<<j)){
                encenderBit(tablero, fila + i, columna + j);
            }
        }
    }
}
uint8_t* nuevaPieza(int anchoTablero, int& fila, int& columna){

    uint8_t* pieza=piezaAleatoria();
    fila=0;
    columna=(anchoTablero-anchoPieza(pieza))/2;
    return pieza;
}
bool procesarMovimiento(uint8_t**tablero, uint8_t*pieza, int alto, int ancho, int& fila, int& columna, char accion){
    switch(accion){
        case 'a':{
            moverIzquierda(tablero, pieza, alto, ancho, fila, columna);
            break;
        }
        case 'd':{
            moverDerecha(tablero, pieza, alto, ancho, fila, columna);
            break;
        }
        case 's':{
            if(bajar(tablero, pieza, alto, ancho, fila, columna)){
                if(!puedeBajar(tablero, pieza, alto, ancho, fila, columna)){
                    return true;
                }
            }
            else{
                return true;
            }
        break;
        }
        case 'w':{
            rotar(tablero, pieza, alto, ancho, fila, columna);
            break;
        }
        default:{
            cout<<"Ingrese una opcion valida."<<endl;
            break;
        }
        }

    return false;
}
