
int centroTablero(int ancho){

    return ancho/2;
}

int desplazamientoAcentro(int centro, int centroFigura){

    return centro - centroFigura;
}

void crearT(int ancho){

    unsigned char T[2];

    int centro = centroTablero(ancho);
    int centroFigura = 1; // Viene del numero de bits, como la figura es de ancho 3, en
    // bits se podria ver como 0 1 2, y su mitad es "1"

    int desplazamiento = desplazamientoAcentro(centro, centroFigura);

    T[0] = (1 << (desplazamiento)) | (1 << (desplazamiento + 1)) |
           (1 << (desplazamiento + 2));
    T[1] = (1 << (desplazamiento + 1));
}

void crearL(int ancho){

    unsigned char L[3];

    int centro = centroTablero(ancho);
    int centroFigura = 0;

    int desplazamiento = desplazamientoAcentro(centro, centroFigura);

    L[0] = (1<<(desplazamiento));
    L[1] = (1<<(desplazamiento));
    L[2] = (1<<(desplazamiento)) | (1<<(desplazamiento + 1));

}

void crearO(int ancho){

    unsigned char O[2];

    int centro = centroTablero(ancho);
    int centroFigura = 0;

    int desplazamiento = desplazamientoAcentro(centro, centroFigura);

    O[0] = (1<<(desplazamiento)) | (1<<(desplazamiento + 1));
    O[1] = (1<<(desplazamiento)) | (1<<(desplazamiento + 1));

}
void crearIoriginal(int ancho){

    unsigned char I[4];

    int centro = centroTablero(ancho);
    int centroFigura = 2;

    int desplazamiento = desplazamientoAcentro(centro, centroFigura);

    I[0] = (1<<(desplazamiento));
    I[1] = (1<<(desplazamiento));
    I[2] = (1<<(desplazamiento));
    I[3] = (1<<(desplazamiento));
}

void crearIdeLado(int ancho){

    unsigned char Igirada[1];

    int centro = centroTablero(ancho);
    int centroFigura = 2;

    int desplazamiento = desplazamientoAcentro(centro, centroFigura);

    Igirada[0] = (1 << (desplazamiento)) | (1 << (desplazamiento + 1)) |
                 (1 << (desplazamiento + 2)) | (1 << (desplazamiento + 3));
}

void crearS(int ancho){

    unsigned char S[3];

    int centro = centroTablero(ancho);
    int centroFigura = 1;

    int desplazamiento = desplazamientoAcentro(centro, centroFigura);

    S[0] = (1 << (desplazamiento + 1)) | (1 << (desplazamiento + 2));
    S[1] = (1 << (desplazamiento + 1));
    S[2] = (1 << (desplazamiento)) | (1 << (desplazamiento + 1));
}

void crearZ(int ancho){

    unsigned char Z[3];

    int centro = centroTablero(ancho);
    int centroFigura = 1;

    int desplazamiento = desplazamientoAcentro(centro, centroFigura);

    Z[0] = (1<<(desplazamiento)) | (1<<(desplazamiento +1));
    Z[1] = (1<<(desplazamiento +1));
    Z[2] = (1<<(desplazamiento +1)) | (1<<(desplazamiento +2));
}






