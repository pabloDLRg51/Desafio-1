#ifndef TABLERO_H
#define TABLERO_H
unsigned char** creacionTablero(int filas, int columnas);
void liberarMemoriaTablero(unsigned char** tablero, int filas);

bool espacio(unsigned char** tablero, int fila, int columna);
void imprimirTablero(unsigned char** tablero, int filas, int columnas);

void encenderBit(unsigned char** tablero, int fila, int columna);
void apagarBit(unsigned char** tablero, int fila, int columna);

bool filaLlena(unsigned **tablero, int fila, int columna);
void eliminarFila(unsigned char**tablero, int fila, int filas, int columnas);
#endif // TABLERO_H
