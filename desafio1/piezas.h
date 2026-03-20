#include <cstdint>
#ifndef PIEZAS_H
#define PIEZAS_H
uint8_t *crearT();
uint8_t *crearJ();
uint8_t *crearO();
uint8_t *crearI();
uint8_t *crearZ();
uint8_t *crearS();
uint8_t *crearL();
void obtenerLimitesrotacion(uint8_t pieza[], int &filaMinima, int &filaMaxima, int &columnaMinima, int &columnaMaxima);
void rotarEnlimites(uint8_t pieza[], uint8_t rotada[], int filaMinima, int filaMaxima, int columnaMinima, int columnaMaxima);
void copiarPieza(uint8_t origen[], uint8_t destino[]);
void rotacion(uint8_t pieza[]);
uint8_t* piezaAleatoria();
#endif // PIEZAS_H
