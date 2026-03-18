#include <cstdint>

int anchoPieza(uint8_t pieza[]){

    int ancho = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {

            if (pieza[i] & (1u << j)) {
                if (j > ancho)
                    ancho = j;
            }
        }
    }

    return ancho + 1;
}

void colocarPieza(uint8_t** tablero, int filas, int columnas,
                  uint8_t* pieza, int filaInicio, int colInicio) {

    for (int i = 0; i < 4; i++) { // filas de la pieza

        for (int j = 0; j < 4; j++) { // columnas (bits)

            if (pieza[i] & (1u << j)) {

                int filaTab = filaInicio + i;
                int colTab = colInicio + j;

                int byteIndex = colTab / 8;
                int bitIndex  = colTab % 8;

                tablero[filaTab][byteIndex] |= (1u << bitIndex);
            }
        }
    }
}
