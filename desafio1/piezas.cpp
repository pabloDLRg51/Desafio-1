#include <cstdint>
int centroTablero(int ancho)

{ /*
    Funcion que calcula el ancho del tablero para poder centrar la figura
   * Parametros:
   * int ancho: una variable tipo entero que contiene el ancho del tablero (por
   * diseño siempre será multiplo de 8)
   *
   * retorno:
   * retorna la posicion en la que esta la mitad del tablero.
   */
    return ancho / 2;
}

int desplazamientoAcentro(int centro, int centroFigura) {
    /*
   *Funcion que calcula cuantas posciones hay que desplazarse respecto al
   * tablero para encontrar el centro de la figura y crearla.
   *
   * Parametros: int
   * centro: El centro del tablero int centroFigura: En base a la geometria de
   * la figura, en que poscion esta su centro.
   *
   *Retorno:
   *Cuanto tenemos que desplazarnos para ubicar el centro de la figura en el
   * centro del tablero.
   */

    return centro - centroFigura;
}

// Creación de las figuras
uint8_t *crearT() {
    /*
   * Funcion que crea la figura T a nivel de bits, usando 1 y 0 y en una matriz
   * de 4 filas y 8 columnas. Se usa static, porque queremos que la pieza viva
   * durante todo el programa
   *
   * Parametro:
   * No usa, crea la T a nivel de bits.
   *
   * retorno:
   * retorna la direccion de memoria del primer elemento del arreglo,
   * garantizando asi que se pueda encontrar siempre la pieza y usarla.
   */

    uint8_t *T = new uint8_t[4];

    T[0] = 0b111;
    T[1] = 0b010;
    T[2] = 0;
    T[3] = 0;

    return T;
}

uint8_t *crearJ() {
    /*
   * Funcion que crea la figura J a nivel de bits, usando 1 y 0 y en una matriz
   * de 4 filas y 8 columnas. Se usa static, porque queremos que la pieza viva
   * durante todo el programa
   *
   * Parametro:
   * No usa, crea la J a nivel de bits.
   *
   * retorno:
   * retorna la direccion de memoria del primer elemento del arreglo,
   * garantizando asi que se pueda encontrar siempre la pieza y usarla.
   */

    uint8_t *J = new uint8_t[4];

    J[0] = 0b01;
    J[1] = 0b01;
    J[2] = 0b11;
    J[3] = 0;

    return J;
}

uint8_t *crearO() {
    /*
   * Funcion que crea la figura O a nivel de bits, usando 1 y 0 y en una matriz
   * de 4 filas y 8 columnas. Se usa static, porque queremos que la pieza viva
   * durante todo el programa
   *
   * Parametro:
   * No usa, crea la O a nivel de bits.
   *
   * retorno:
   * retorna la direccion de memoria del primer elemento del arreglo,
   * garantizando asi que se pueda encontrar siempre la pieza y usarla.
   */

    uint8_t *O = new uint8_t[4];

    O[0] = 0b11;
    O[1] = 0b11;
    O[2] = 0;
    O[3] = 0;

    return O;
}
uint8_t *crearI() {
    /*
   * Funcion que crea la figura I a nivel de bits,
   * usando 1 y 0 y en una matriz de 4 filas y 8 columnas. Se usa static, porque
   * queremos que la pieza viva durante todo el programa
   *
   * Parametro:
   * No usa, crea la I en su forma original a nivel de bits.
   *
   * retorno:
   * retorna la direccion de memoria del primer elemento del arreglo,
   * garantizando asi que se pueda encontrar siempre la pieza y usarla.
   */

    uint8_t *I = new uint8_t[4];

    I[0] = 0b1;
    I[1] = 0b1;
    I[2] = 0b1;
    I[3] = 0b1;

    return I;
}

uint8_t *crearZ() {
    /*
   * Funcion que crea la figura Z a nivel de bits, usando 1 y 0 y en una matriz
   * de 4 filas y 8 columnas. Se usa static, porque queremos que la pieza viva
   * durante todo el programa
   *
   * Parametro:
   *No usa, crea la Z a nivel de bits.
   *
   * retorno:
   * retorna la direccion de memoria del primer elemento del arreglo,
   * garantizando asi que se pueda encontrar siempre la pieza y usarla.
   */

    uint8_t *Z = new uint8_t[4];

    Z[0] = 0b11;
    Z[1] = 0b011;
    Z[2] = 0;
    Z[3] = 0;

    return Z;
}

uint8_t *crearS() {
    /*
   * Funcion que crea la figura S a nivel de bits, usando 1 y 0 y en una matriz
   * de 4 filas y 8 columnas. Se usa static, porque queremos que la pieza viva
   * durante todo el programa
   *
   * Parametro:
   * No usa, crea la S a nivel de bits.
   *
   * retorno:
   * retorna la direccion de memoria del primer elemento del arreglo,
   * garantizando asi que se pueda encontrar siempre la pieza y usarla.
   */

    uint8_t *S = new uint8_t[4];

    S[0] = 0b011;
    S[1] = 0b11;
    S[2] = 0;
    S[3] = 0;

    return S;
}

uint8_t *crearL() {
    /*
   * Funcion que crea la figura L a nivel de bits, usando 1 y 0 y en una matriz
   * de 4 filas y 8 columnas. Se usa static, porque queremos que la pieza viva
   * durante todo el programa
   *
   * Parametro:
   * No usa, crea la L a nivel de bits.
   *
   * retorno:
   * retorna la direccion de memoria del primer elemento del arreglo,
   * garantizando asi que se pueda encontrar siempre la pieza y usarla.
   */

    uint8_t *L = new uint8_t[4];

    L[0] = 0b1;
    L[1] = 0b1;
    L[2] = 0b11;
    L[3] = 0;

    return L;
}

// Rotación de las figuras

void rotacionesAntihorarias(uint8_t pieza[]) {
    /*
Funcion que rota la figura 90 grados hacia la izquierda. Aprovecha que la figura
se guarda siempre como una matriz de 4x4 y para rotarla toma cada celda y
transforma su posicion en la fila a la de la columna, y la de la columna la
modifica usando "tamaño-1-fila".

Parametro:
unsigned char pieza[]: un arreglo de char, que basicamente es una matriz de n
filas por 8 columnas que son los bits que ocupa un char. Usa unsigned para que
el bit mas significativo no se altere por el signo.

Retorno:
No retorna nada, modifica la pieza original al rotarla.
*/

    uint8_t rotacion[4] = {0};

    for (int fila = 0; fila < 4; fila++) {

        for (int columna = 0; columna < 4; columna++) {

            if (pieza[fila] & (1 << columna)) {

                rotacion[columna] |= (1 << (3 - fila)); // La operacion viene de rotar
                // geometricamente una matriz, donde (fila, columna) -> (columna,
                // tamaño-1-fila), haciendo que las filas pasen a columnas y las
                // columnas a filas
            }
        }
    }

    for (int auxiliar = 0; auxiliar < 4; auxiliar++) {

        pieza[auxiliar] =
            rotacion[auxiliar]; // Cambiamos la pieza para que ahora este rotada, al
        // rotar 4 veces siempre se puede volver a la
        // orignal
    }
}

void rotacionesHorarias(uint8_t pieza[]) {
    /*
Funcion que rota la figura 90 grados hacia la derecha. Aprovecha que la figura
se guarda siempre como una matriz de 4x4 y para rotarla toma cada celda y
transforma su posicion en la fila a la de la columna, y la de la columna la
modifica usando "tamaño-1-fila".

Parametro:
unsigned char pieza[]: un arreglo de char, que basicamente es una matriz de n
filas por 8 columnas que son los bits que ocupa un char. Usa unsigned para que
el bit mas significativo no se altere por el signo.

Retorno:
No retorna nada, modifica la pieza original al rotarla.
*/

    uint8_t rotacion[4] = {0};

    for (int fila = 0; fila < 4; fila++) {

        for (int columna = 0; columna < 4; columna++) {

            if (pieza[fila] & (1 << columna)) {

                rotacion[3 - columna] |= (1 << fila);
            }
        }
    }

    for (int auxiliar = 0; auxiliar < 4; auxiliar++) {

        pieza[auxiliar] =
            rotacion[auxiliar]; // Cambiamos la pieza para que ahora este rotada, al
        // rotar 4 veces siempre se puede volver a la
        // orignal
    }
}
