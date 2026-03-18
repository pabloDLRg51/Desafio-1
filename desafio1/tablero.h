#include <cstdint>
#ifndef TABLERO_H
#define TABLERO_H
uint8_t **creacionTablero(int filas, int columnas);
void liberarMemoriaTablero(uint8_t **tablero, int filas);

bool espacio(uint8_t **tablero, int fila, int columna);
void imprimirTablero(uint8_t **tablero, int filas, int columnas);

void encenderBit(uint8_t **tablero, int fila, int columna);
void apagarBit(uint8_t **tablero, int fila, int columna);

bool filaLlena(uint8_t **tablero, int fila, int columna);
void eliminarFila(uint8_t **tablero, int fila, int filas, int columnas);
#endif // TABLERO_H
