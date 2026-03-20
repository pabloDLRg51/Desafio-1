#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include "juego.h"

using namespace std;

int main(){
    int filas=10;
    int columnas=16;
    uint8_t** tablero = creacionTablero(filas, columnas);
    uint8_t* pieza = 0;
    int fila = 0, columna =0;
    while (true){
        pieza = nuevaPieza(columnas, fila, columna);
        if (colision(tablero, pieza, filas, columnas, fila, columna)) {
            cout << "Game Over";
            delete[] pieza;
            break;
        }
        while (true){
            imprimirTablero(tablero, filas, columnas, pieza, fila, columna);
            cout << "Accion: [A]Izquierda [D]Derecha [S]Bajar [W]Rotar [Q]SALIR  ";
            char accion;
            cin >> accion;
            bool fijar = procesarMovimiento(tablero, pieza,filas, columnas,fila, columna,accion);
            if (fijar) {
                fijarPieza(tablero, pieza, fila, columna);
                for (int i = filas - 1; i >= 0; i--) {
                    if (filaLlena(tablero, i, columnas)) {
                        eliminarFila(tablero, i, columnas);
                        i++;
                    }
                }
                delete[] pieza;
                break;
            }
        }
    }

    liberarMemoriaTablero(tablero, filas);
    return 0;
}


