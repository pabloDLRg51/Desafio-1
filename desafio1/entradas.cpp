#include <iostream>
using namespace std;

int leerEntero(){
/*
Lee un numero entero ingresado por el usuario y valida que la entrada sea correcta. Si el usuario ingresa caracteres de mas o errores en la lectura, limpia la entrada y lanza una excepcion.

retorna:
int: valor entero ingresado correctamente.
*/
    int valor;
    cin >> valor;
     //verifica si hubo error o si el usuario escribio mas de un valor
    if(cin.fail() || cin.peek()!='\n'){
        cin.clear();
        //limpia caracteres restantes de la entrada
        while(cin.peek()!='\n'){
            cin.get();
        }
        cin.get(); //consume el salto de linea
        throw 1;
    }
    return valor;
}

int leerFilas(){
/*
Solicita al usuario el numero de filas del tablero. valida que el valor sea mayor o igual a 8.

retorna:
int: numero de filas valido
*/
    int filas;
    while(true){
        cout<<"Ingrese el numero de filas (deben ser mayor o igual a 8): ";
        try{
            filas=leerEntero();
            //valida tamaño minimo del tablero
            if(filas<8) throw 1;
            return filas;
        } catch(...){
            cout << "Entrada invalida\n";
        }
    }
}

int leerColumnas(){
/*
Solicita al usuario el numero de columnas del tablero. valida que sea mayor o igual a 8 y multiplo de 8.

retorna:
int: numero de columnas valido
*/
    int columnas;
    while(true){
        cout<< "Ingrese el numero de columnas (deben ser mayor o igual a 8 y multiplo de 8): ";

        try{
             //valida condiciones del tablero
            columnas=leerEntero();
            if(columnas < 8 || columnas % 8 != 0) throw 1;
            return columnas;
        } catch(...){
            cout << "Entrada invalida\n";
        }
    }
}
char leerAccion(){
/*
Solicita al usuario una accion para controlar la pieza. Valida que solo se ingrese un caracter y que sea una opcion valida.

Opciones:
a: mover izquierda
d: mover derecha
s: bajar
w: rotar
q: salir

retorna:
char: accion valida ingresada por el usuario
*/
    char accion;
    while(true){
        cout<<"Accion: [a]Izquierda [d]Derecha [s]Bajar [w]Rotar [q]SALIR\n";
        cout<<"Ingrese una opcion: ";
        try{
            cin>>accion;
            if(cin.peek()!='\n'){
                while(cin.peek()!='\n'){
                    cin.get();
                }
                cin.get();
                throw 1; //señal de error que recibe el catch
            }
            if((accion>='A')&& (accion <= 'Z')){
                accion=accion + 32;
            }
            if((accion!='a') && (accion!='d') &&(accion!='s') && (accion!='w')&&(accion!='q')){
                throw 2;
            }
            return accion;
        } catch(...){
            cout << "Entrada invalida\n";
        }
    }
}
