#include <cstdint>

int anchoPieza(uint8_t pieza[]) {

    int ancho = 0;

    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 4; columna++) {

            if (pieza[fila] & (1 << columna)) {
                if (columna > ancho)
                    ancho = columna;
            }
        }
    }

    return ancho + 1;
}


void colocarPieza(uint8_t **tablero, uint8_t *pieza, int ancho) {

    int columnaInicio = (ancho - anchoPieza(pieza)) / 2;
    int filaInicio = 0;

    for (int filaPieza = 0; filaPieza < 4; filaPieza++) { // filas de la pieza

        for (int columnaPieza = 0; columnaPieza < 4;
             columnaPieza++) { // columnas (bits)

            if (pieza[filaPieza] & (1 << columnaPieza)) {

                int filaTablero = filaInicio + filaPieza;
                int columnaTablero = columnaInicio + columnaPieza;

                int byteIndex =
                    columnaTablero /
                                8; // busca en que byte de la columna hay que ubicar la pieza
                int bitIndex = columnaTablero %
                               8; // busca en que bit dentro del byte ubico la pieza

                tablero[filaTablero][byteIndex] |= (1 << bitIndex);
            }
        }
    }
}

bool colision(uint8_t **tablero, uint8_t pieza[], int alto, int ancho,
              int filaPieza, int columnaPieza) {

    for (int filas = 0; filas < 4; filas++) {
        for (int columnas = 0; columnas < 4; columnas++) {

            if (pieza[filas] & (1 << columnas)) {

                int filaTablero = filaPieza + filas;
                int columnaTablero = columnaPieza + columnas;

                if (filaTablero >= alto || columnaTablero >= ancho) {

                    return true;
                }

                int byteIndex = columnaTablero / 8;
                int bitIndex = columnaTablero % 8;

                if (tablero[filaTablero][byteIndex] & (1 << bitIndex)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// void moverPieza(uint8_t** tablero, uint8_t* pieza, int filas, int columnas)

