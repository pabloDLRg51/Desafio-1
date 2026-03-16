#ifndef PIEZAS_H
#define PIEZAS_H
int centroTablero(int ancho);
int desplazamientoAcentro(int centro, int centroFigura);
unsigned char *crearT();
unsigned char *crearJ();
unsigned char *crearO();
unsigned char *crearI();
unsigned char *crearZ();
unsigned char *crearS();
unsigned char *crearL();
void rotacionesHorarias(unsigned char pieza[]);
void rotacionesAntihorarias(unsigned char pieza[]);
#endif // PIEZAS_H
