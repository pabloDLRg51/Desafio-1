#include <cstdint>
#ifndef JUEGO_H
#define JUEGO_H
int anchoPieza(uint8_t pieza[]);
/*void colocarPieza(uint8_t** tablero, uint8_t* pieza, int ancho);*/
bool colision(uint8_t** tablero, uint8_t pieza[], int alto, int ancho, int filaPieza, int columnaPieza);

bool moverIzquierda(uint8_t**tablero, uint8_t* pieza, int alto, int ancho, int fila, int& columna);
bool moverDerecha(uint8_t**tablero, uint8_t* pieza, int alto, int ancho, int fila, int& columna);
bool bajar(uint8_t** tablero, uint8_t* pieza,int alto, int ancho,int& fila, int columna);
void rotar(uint8_t** tablero, uint8_t* pieza, int alto, int ancho, int fila, int columna);

void fijarPieza(uint8_t** tablero, uint8_t* pieza,int fila, int columna);
uint8_t* nuevaPieza(int anchoTablero, int& fila, int& columna);

bool procesarMovimiento(uint8_t**tablero, uint8_t*pieza, int alto, int ancho, int& fila, int& columna, char accion, bool& movimientoHorizontalUsado);
#endif // JUEGO_H
