#include "piezas.h"
#include "tablero.h"
#include <cstdint>
#include <iostream>
using namespace std;
int anchoPieza(uint8_t pieza[]) {
    /*funcion que calcula el ancho de una pieza representada en formato 4x4 usando
  btis recorre la pieza y determina la columna más a la derecha que está
  ocupada, retornando el ancho real de la pieza.

  parametros:
  uint8_t pieza[]:arreglo que representa la pieza en formato de bits.

  retorna:
  int:ancho de la pieza (numero de columnas ocupadas).
   */
    int ancho = 0;//guarda la mna maxima encontrada con bits en 1

    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 4; columna++) {
            //verifica si en esa posicion hay un bit en 1, con un mascara
            if (pieza[fila] & (1 << columna)) {
                //Si la columna actual es mayor que la maxima guardada, actualiza el ancho
                if (columna > ancho)
                    ancho = columna;
            }
        }
    }

    return ancho + 1;//se suma 1 porque las columnas empiezan en 0
}
bool colision(uint8_t **tablero, uint8_t pieza[], int alto, int ancho,
              int filaPieza, int columnaPieza) {
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
    //recorre la matriz 4x4 de la pieza
    for(int filas = 0; filas < 4; filas++) {
        for(int columnas = 0; columnas < 4; columnas++) {
            //verifica si hay un bloque activo en la pieza
            if(pieza[filas]&(1<<columnas)){
                //calcula la posicion en el tablero
                int filaTablero=filaPieza+filas;
                int columnaTablero=columnaPieza+columnas;
                //verifica si se sale de los limites del tablero
                if((columnaTablero<0)||(filaTablero>=alto) ||
                    (columnaTablero >= ancho)) {
                    return true;//hay colision en el borde
                }
                //si esta por encima del tablero no se valida colision, para cuando la pieza esta entrando
                if(filaTablero<0){
                    continue;
                }
                //verifica si choca con celdas ya ocupadas
                if(filaTablero>=0){
                    //ubicar el byte y bit dentro del tablero
                    int byteIndex=columnaTablero/8;
                    int bitIndex=columnaTablero%8;
                    //revisa si el ese bit ya esta ocupado
                    if (tablero[filaTablero][byteIndex]&(1<< bitIndex)) {
                        return true;//retorna colision con otra pieza
                    }
                }
            }
        }
    }
    //si no se detecto ningun problema, no hay colision
    return false;
}

bool moverIzquierda(uint8_t **tablero, uint8_t *pieza, int alto, int ancho,
                    int fila, int &columna) {
    /*Funcion que mueve la posicion una posición hacia a la izquierda, revisa si
  al moverse a la izquierda hay colision, si no hay colision, actualiza la
  columna y mueve la pieza. si hay colision, no hace nada.

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
    //verifica si al moverse a la izquierda habra colision
    if (!colision(tablero, pieza, alto, ancho, fila, columna - 1)) {
        columna--;//si no hay colision, actualiza la posicion real
        return true;
    }
    return false;
}
bool moverDerecha(uint8_t **tablero, uint8_t *pieza, int alto, int ancho,
                  int fila, int &columna) {
    /*Funcion que mueve la posicion una posición hacia a la derecja, revisa si al
moverse a la derecha hay colision, si no hay colision, actualiza la columna y
mueve la pieza. si hay colision, no hace nada.

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
    if (!colision(tablero, pieza, alto, ancho, fila, columna + 1)) {
        columna++;
        return true;
    }
    return false;
}
bool bajar(uint8_t **tablero, uint8_t *pieza, int alto, int ancho, int &fila,
           int columna) {
    /*
   Funcion que baja la pieza una posicion hacia abajo. Revisa si al mover la
  pieza una fila abajo hay colision, si no hay colision, actualiza la fila y la
  pieza baja. Si hay colision, no se mueve.

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
    //verifica si hay colision al mover hacia abajo
    if (!colision(tablero, pieza, alto, ancho, fila + 1, columna)) {
        fila++;//si no hay colision, se actualiza la fila
        return true;
    }
    return false;
}
bool puedeBajar(uint8_t **tablero, uint8_t *pieza, int alto, int ancho,
                int fila, int columna) {
    /*Funcion que verifica si la pieza puede bajar una posicion. Revisa si al
  mover la pieza una fila hacia abajo hay colision. No modifica la posicion,
  solo hace la comprobacion.

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
    //si no hay colisión una fila más abajo, puede bajar
    return !colision(tablero, pieza, alto, ancho, fila + 1, columna);
}
void rotar(uint8_t **tablero, uint8_t *pieza, int alto, int ancho, int fila,
           int columna){
    //rota la pieza 90 grados
    rotacion(pieza);
    //verifica si despues de rotar hay colision
    if(colision(tablero, pieza, alto, ancho, fila, columna)){
        //si hay colision, se dehace la rtoacion, rotando la ficha 3 veces volviendola a su estado original
        rotacion(pieza);
        rotacion(pieza);
        rotacion(pieza);
    }
}
void fijarPieza(uint8_t **tablero, uint8_t *pieza, int fila, int columna) {
    /*Funcion que fija la pieza en el tablero. Recorre la pieza y por cada bloque
  activo, enciende el bit correspondiente en el trablero. Es decir, la pieza
  pasa de ser movible a quedar guardada en el tablero

  parametros:
  uint8_t **tablero: puntero a puntero que representa el tablero
  uint8_t *pieza: pieza actual en formato 4x4 usando bits
  int fila: fila donde esta posicionada la pieza.
  int columna: columna donde esta posicionada la pieza

  no retorna nada
  */
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            //verifica si hay un bloque activo en la pieza
            if (pieza[i]&(1<<j)){
                //calcula la posicion de la pieza en el tablero
                int filaTablero = fila + i;
                int columnaTablero = columna + j;
                //evita escribir fuera del tablero
                if ((filaTablero >= 0) && (columnaTablero >= 0)){
                    encenderBit(tablero, filaTablero, columnaTablero);//enciende el bit en el tablero
                }
            }
        }
    }
}
uint8_t *nuevaPieza(int anchoTablero, int &fila, int &columna) {
    /*
   Funcion que genera una nueva pieza y la posiciona en el tablero, crea una
  pieza aleatoria, la ubica en la parte superior del tablero (fila 0) y la
  centra horizontalmente segun su ancho.

  parametros:
  int anchoTablero: numero de columnas del tablero.
  int& fila: fila donde aparecera la pieza.
  int& columna: columna donde aparecera la pieza.

  retorna:
  uint8_t* pieza: puntero a la nueva pieza generada.

  */
    uint8_t *pieza=piezaAleatoria();//genera la pieza de forma aleatoria
    int filaMinima, filaMaxima, columnaMinima, columnaMaxima;//limites de la pieza
    obtenerLimitesrotacion(pieza, filaMinima, filaMaxima, columnaMinima, columnaMaxima);//zona donde hay bits en 1 de la pieza
    int altura = filaMaxima - filaMinima + 1;//altura de la pieza
    fila = -(altura / 2);//posicion la pieza arriba del tablero
    columna = (anchoTablero - anchoPieza(pieza)) / 2;//centra la pieza en el tablero
    return pieza;
}
bool procesarMovimiento(uint8_t **tablero, uint8_t *pieza, int alto, int ancho,
                        int &fila, int &columna, char accion,
                        bool &movimientoHorizontalUsado) {
    /*
Procesa la accion ingresada por el usuario y actualiza la posicion de la pieza.
Permite mover a la izquierda, derecha, bajar o rotar. Controla que solo se pueda
realizar un movimiento horizontal por turno.

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
            moverIzquierda(tablero, pieza, alto, ancho, fila, columna);
            movimientoHorizontalUsado=true;//condicion del movimiento horizontal, para que no quede en un bucle infinito
        }
        break;
    case 'd':
        if(!movimientoHorizontalUsado){
            moverDerecha(tablero, pieza, alto, ancho, fila, columna);
            movimientoHorizontalUsado=true;
        }
        break;
    case 's':
        //intenta bajar la pieza
        if(bajar(tablero, pieza, alto, ancho, fila, columna)){
            movimientoHorizontalUsado=false;//si baja correctamente, se reinicia el uso del movimiento horizontal
            if (!puedeBajar(tablero, pieza, alto, ancho, fila, columna)){
                return true;
            }
        }
        else{
            return true;//si no baja, ya colisiono
        }
        break;
    case 'w':
        rotar(tablero, pieza, alto, ancho, fila, columna);
        break;
    default:
        cout << "Ingrese una opcion valida." << endl;
        break;
    }
    return false;//puede seguir bajando
}
