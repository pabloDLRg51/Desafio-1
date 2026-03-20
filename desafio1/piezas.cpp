#include <cstdint>
#include <random>

// Creación de las figuras
uint8_t *crearT() {
    /*
Funcion que crea la figura T a nivel de bits, representandola como una matriz
de 4 filas donde cada fila contiene 8 bits. Cada bit en 1 representa un bloque
activo de la pieza.

parametros:
no recibe parametros

retorno:
uint8_t*: direccion de memoria del arreglo que contiene la pieza T
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
Funcion que crea la figura J a nivel de bits, representandola como una matriz
de 4 filas donde cada fila contiene 8 bits. Cada bit en 1 representa un bloque
activo de la pieza.

parametros:
no recibe parametros

retorno:
uint8_t*: direccion de memoria del arreglo que contiene la pieza J
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
Funcion que crea la figura O a nivel de bits, representandola como una matriz
de 4 filas donde cada fila contiene 8 bits. Cada bit en 1 representa un bloque
activo de la pieza.

parametros:
no recibe parametros

retorno:
uint8_t*: direccion de memoria del arreglo que contiene la pieza O
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
Funcion que crea la figura I a nivel de bits, representandola como una matriz
de 4 filas donde cada fila contiene 8 bits. Cada bit en 1 representa un bloque
activo de la pieza.

parametros:
no recibe parametros

retorno:
uint8_t*: direccion de memoria del arreglo que contiene la pieza I
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
Funcion que crea la figura Z a nivel de bits, representandola como una matriz
de 4 filas donde cada fila contiene 8 bits. Cada bit en 1 representa un bloque
activo de la pieza.

parametros:
no recibe parametros

retorno:
uint8_t*: direccion de memoria del arreglo que contiene la pieza Z
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
Funcion que crea la figura S a nivel de bits, representandola como una matriz
de 4 filas donde cada fila contiene 8 bits. Cada bit en 1 representa un bloque
activo de la pieza.

parametros:
no recibe parametros

retorno:
uint8_t*: direccion de memoria del arreglo que contiene la pieza S
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
Funcion que crea la figura L a nivel de bits, representandola como una matriz
de 4 filas donde cada fila contiene 8 bits. Cada bit en 1 representa un bloque
activo de la pieza.

parametros:
no recibe parametros

retorno:
uint8_t*: direccion de memoria del arreglo que contiene la pieza L
*/

    uint8_t *L = new uint8_t[4];

    L[0] = 0b1;
    L[1] = 0b1;
    L[2] = 0b11;
    L[3] = 0;

    return L;
}

// Rotación de las figuras

void obtenerLimitesrotacion(uint8_t pieza[], int &filaMinima, int &filaMaxima,int &columnaMinima, int &columnaMaxima) {
    /*
Funcion que obtiene los limites reales de la pieza dentro de la matriz de 4x4.
Recorre todas las posiciones y determina la primera y ultima fila y columna
donde existen bits activos.

Estos limites permiten trabajar unicamente con la region donde esta la pieza,
ignorando espacios vacios.

parametros:
uint8_t *pieza: pieza en formato 4x4 usando bits
int &filaMinima: referencia donde se guarda la fila inicial de la pieza
int &filaMaxima: referencia donde se guarda la fila final de la pieza
int &columnaMinima: referencia donde se guarda la columna inicial de la pieza
int &columnaMaxima: referencia donde se guarda la columna final de la pieza

no retorna nada
*/
    filaMinima = 4;
    filaMaxima = -1;
    columnaMinima = 4;
    columnaMaxima = -1;

    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 4; columna++) {
            if (pieza[fila] & (1 << columna)) {
                if (fila < filaMinima)
                    filaMinima = fila;
                if (fila > filaMaxima)
                    filaMaxima = fila;
                if (columna < columnaMinima)
                    columnaMinima = columna;
                if (columna > columnaMaxima)
                    columnaMaxima = columna;
            }
        }
    }
}

void rotarEnlimites(uint8_t pieza[], uint8_t rotada[], int filaMinima,int filaMaxima, int columnaMinima, int columnaMaxima) {
    /*
Funcion que rota la pieza 90 grados en sentido horario sin desplazarla dentro
de la matriz de 4x4. Utiliza los limites de la pieza para trabajar unicamente
sobre la region donde existen bits activos.

Por cada bloque activo, calcula su nueva posicion aplicando la transformacion
de rotacion en coordenadas relativas y lo ubica en la nueva matriz.

parametros:
uint8_t *pieza: pieza original en formato 4x4 usando bits
uint8_t *rotada: arreglo donde se almacena la pieza rotada
int filaMinima: fila donde inicia la pieza
int filaMaxima: fila donde termina la pieza
int columnaMinima: columna donde inicia la pieza
int columnaMaxima: columna donde termina la pieza

no retorna nada
*/
    int alto = filaMaxima - filaMinima + 1;
    for (int fila =filaMinima; fila <= filaMaxima; fila++) {
        for (int columna= columnaMinima; columna <= columnaMaxima; columna++) {
            if (pieza[fila] & (1 << columna)) {
                int nuevaFila = filaMinima + (columna - columnaMinima);
                int nuevaColumna = columnaMinima + (alto - 1 - (fila - filaMinima));
                rotada[nuevaFila] |= (1 << nuevaColumna);
            }
        }
    }
}

void copiarPieza(uint8_t origen[], uint8_t destino[]) {
    /*
Funcion que copia el contenido de una pieza a otra. Recorre el arreglo y copia
cada uno de los valores, permitiendo transferir la informacion sin compartir
la misma referencia en memoria.

parametros:
uint8_t *origen: pieza de donde se copian los datos
uint8_t *destino: pieza donde se almacenan los datos copiados

no retorna nada
*/
    for (int auxiliar = 0; auxiliar < 4; auxiliar++) {
        destino[auxiliar] = origen[auxiliar];
    }
}

void rotacion(uint8_t pieza[]) {
    /*
Funcion que rota la pieza 90 grados en sentido horario sin desplazarla. Primero
obtiene los limites reales de la pieza, luego realiza la rotacion dentro de esos
limites y finalmente copia el resultado a la pieza original.

parametros:
uint8_t *pieza: pieza en formato 4x4 usando bits

no retorna nada
*/
    uint8_t rotada[4] = {0};

    int filaMinima, filaMaxima, columnaMinima, columnaMaxima;

    obtenerLimitesrotacion(pieza, filaMinima, filaMaxima, columnaMinima,
                           columnaMaxima);
    rotarEnlimites(pieza, rotada, filaMinima, filaMaxima, columnaMinima,
                   columnaMaxima);
    copiarPieza(rotada, pieza);
}


uint8_t *piezaAleatoria() {
    /*
Funcion que genera una pieza aleatoria entre las figuras disponibles. Utiliza
un generador de numeros aleatorios para seleccionar una pieza y retorna su
direccion de memoria.

parametros:
no recibe parametros

retorno:
uint8_t*: direccion de memoria de la pieza generada aleatoriamente
*/
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 6);

    int random = dist(gen);

    if (random == 0)
        return crearT();
    else if (random == 1)
        return crearJ();
    else if (random == 2)
        return crearO();
    else if (random == 3)
        return crearI();
    else if (random == 4)
        return crearZ();
    else if (random == 5)
        return crearS();
    else
        return crearL();
}
