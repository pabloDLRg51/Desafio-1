#include <cstdint>
#ifndef PIEZAS_H
#define PIEZAS_H
int centroTablero(int ancho);
uint8_t *crearT();
uint8_t *crearJ();
uint8_t *crearO();
uint8_t *crearI();
uint8_t *crearZ();
uint8_t *crearS();
uint8_t *crearL();
void rotacionesAntihorarias(uint8_t pieza[]);
void rotacionesHorarias(uint8_t pieza[]);
#endif // PIEZAS_H
