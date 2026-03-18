#include <cstdint>
#ifndef JUEGO_H
#define JUEGO_H
int anchoPieza(uint8_t pieza[]);
void colocarPieza(uint8_t** tablero, uint8_t* pieza, int ancho);
bool colision(uint8_t** tablero, uint8_t pieza[], int alto, int ancho, int filaPieza, int columnaPieza);
#endif // JUEGO_H
