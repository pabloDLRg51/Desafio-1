#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include "juego.h"
#include "entradas.h"
using namespace std;
int main(){
    //pedir al usuario las dimensiones del tablero
    int filas = leerFilas();
    int columnas = leerColumnas();
    //crea el tablero dinamico
    uint8_t** tablero = creacionTablero(filas, columnas);
    uint8_t* pieza;//pieza actual
    int fila,columna;//posicion de la pieza
    bool gameOver=false;//contrala el fin del juego
    while(!gameOver){
        bool movimientoHorizontalUsado= false;
        pieza=nuevaPieza(columnas,fila, columna);
        while(true){
            imprimirTablero(tablero, filas, columnas, pieza, fila, columna);//Muestra el tablero con la pieza actual
            char accion = leerAccion();

            if(accion == 'q'){
                cout << "Saliendo...\n";
                delete[] pieza;
                gameOver = true;
                break;
            }
            bool fijar = procesarMovimiento(tablero, pieza,filas, columnas,fila, columna,accion, movimientoHorizontalUsado);//procesa la ccion ingressada por el usuario
            //si la pieza ya no puede moverse, se fija
            if (fijar){
            //Si la pieza no entro completamente al tablero es el fin del juego
                if(fila<0){
                    cout<<"Game over\n";
                    delete[] pieza;
                    gameOver = true;
                    break;
                }
                fijarPieza(tablero, pieza, fila, columna);
                //verifica y elimina filas completas
                for (int i=filas-1;i>=0;i--){
                    if (filaLlena(tablero,i,columnas)){
                        eliminarFila(tablero,i,columnas);
                        i++;//revisa la fila nuevamente
                    }
                }
                //liberacion de memoria
                delete[] pieza;
                break;
            }
        }
    }
    liberarMemoriaTablero(tablero, filas);
    return 0;
}


