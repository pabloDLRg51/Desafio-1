#ifndef TABLERO_H
#define TABLERO_H
unsigned char** creacionTablero(int filas, int columnas);
void liberarMemoriaTablero(unsigned char** tablero, int filas);
bool espacio(unsigned char** tablero, int fila, int columna);
void imprimirTablero(unsigned char** tablero, int filas, int columnas);
void encenderBit(unsigned char** tablero, int fila, int columna);
#endif // TABLERO_H
