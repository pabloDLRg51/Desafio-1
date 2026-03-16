
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

unsigned char *crearT() {
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

    static unsigned char T[4];

    T[0] = (1 << 0) | (1 << 1) | (1 << 2);
    T[1] = (1 << 1);
    T[2] = 0;
    T[3] = 0;

    return T;
}

unsigned char *crearJ() {
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

    static unsigned char J[4];

    J[0] = (1 << 0);
    J[1] = (1 << 0);
    J[2] = (1 << 0) | (1 << 1);
    J[3] = 0;

    return J;
}

unsigned char *crearO() {
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

    static unsigned char O[4];

    O[0] = (1 << 0) | (1 << 1);
    O[1] = (1 << 0) | (1 << 1);
    O[2] = 0;
    O[3] = 0;

    return O;
}
unsigned char *crearIoriginal() {
    /*
   * Funcion que crea la figura I en su posicion original a nivel de bits,
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

    static unsigned char I[4];

    I[0] = (1 << 0);
    I[1] = (1 << 0);
    I[2] = (1 << 0);
    I[3] = (1 << 0);

    return I;
}

unsigned char *crearIdeLado() {
    /*
   * Funcion que crea la figura I ya rotada a nivel de bits, usando 1 y 0 y en
   * una matriz de 4 filas y 8 columnas. Se usa static, porque queremos que la
   * pieza viva durante todo el programa; ademas, para este caso en particular,
   * se crear la I ya rotada por a parte, ya que es más facil de manejar asi
   *
   * Parametro:
   * No usa, crea la I en su forma rotada a nivel de bits.
   *
   * retorno:
   * retorna la direccion de memoria del primer elemento del arreglo,
   * garantizando asi que se pueda encontrar siempre la pieza y usarla.
   */

    static unsigned char Igirada[4];

    Igirada[0] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
    Igirada[1] = 0;
    Igirada[2] = 0;
    Igirada[3] = 0;

    return Igirada;
}

unsigned char *crearZ() {
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

    static unsigned char Z[4];

    Z[0] = (1 << 1) | (1 << 2);
    Z[1] = (1 << 1) | (1 << 0);
    Z[2] = 0;
    Z[3] = 0;

    return Z;
}

unsigned char *crearS() {
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

    static unsigned char S[4];

    S[0] = (1 << 0) | (1 << 1);
    S[1] = (1 << 1) | (1 << 2);
    S[2] = 0;
    S[3] = 0;

    return S;
}

unsigned char *crearL() {
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

    static unsigned char L[4];

    L[0] = (1 << 1);
    L[1] = (1 << 1);
    L[2] = (1 << 0) | (1 << 1);
    L[3] = 0;

    return L;
}

// Rotación de las figuras

void rotacionesHorarias(unsigned char pieza[]) {

    unsigned char rotacion[4] = {0};

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

void rotacionesAntihorarias(unsigned char pieza[]) {

    unsigned char rotacion[4] = {0};

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
