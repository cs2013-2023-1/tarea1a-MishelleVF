#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    ptr = reinterpret_cast<float **>(new int *[getFilas()]);
    for (int i = 0; i < getFilas(); i++) {
        ptr[i] = reinterpret_cast<float *>(new int[getFilas()]);
    }
    for (int i = 0; i < getFilas(); i++) {
        for (int j = 0; j < getFilas(); j++) {
            ptr[i][j] = rand() / static_cast<float>(RAND_MAX);
        }
    }

}

Matriz2D::Matriz2D(int n): filas(n), columnas(n){
    // Constructor con un parametro
    ptr = reinterpret_cast<float **>(new int *[getFilas()]);
    for (int i = 0; i < getFilas(); i++) {
        ptr[i] = reinterpret_cast<float *>(new int[getFilas()]);
    }
    for (int i = 0; i < getFilas(); i++) {
        for (int j = 0; j < getFilas(); j++) {
            ptr[i][j] = rand() / static_cast<float>(RAND_MAX);
        }
    }
}

Matriz2D::Matriz2D(int n, int m): filas(n), columnas(m){
    // Constructor con dos parametros
    ptr = reinterpret_cast<float **>(new int *[getFilas()]);
    for (int i = 0; i < getFilas(); i++) {
        ptr[i] = reinterpret_cast<float *>(new int[getColumnas()]);
    }
    for (int i = 0; i < getFilas(); i++) {
        for (int j = 0; j < getColumnas(); j++) {
            ptr[i][j] = rand() / static_cast<float>(RAND_MAX);
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    this -> filas = m.filas;
    this -> columnas = m.columnas;
    ptr = reinterpret_cast<float **>(new int *[getFilas()]);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            ptr[i][j] = m.ptr[i][j];
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    this -> filas = m.filas;
    this -> columnas = m.columnas;
    ptr = m.ptr;
    m.ptr = nullptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D transpuesta(m.columnas, m.filas);
    for(int i=0; i<transpuesta.filas; i++){
        for(int j=0; j<transpuesta.columnas; j++){
            transpuesta.ptr[i][j] = m.ptr[i][j];
        }
    }
    return transpuesta;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for (int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            os << m.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D sumaMatriz(m1.filas, m1.filas);
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.filas; j++){
            sumaMatriz.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
        }
    }
    return sumaMatriz;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D restaMatriz(m1.filas, m1.filas);
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.filas; j++){
            restaMatriz.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
        }
    }
    return restaMatriz;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D multiMatriz(m1.filas, m2.columnas);
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.filas; j++){
            multiMatriz.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
        }
    }
    return multiMatriz;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D sumaEntero(m.filas, m.columnas);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            sumaEntero.ptr[i][j] = m.ptr[i][j] + n;
        }
    }
    return sumaEntero;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D restaEntero(m.filas, m.columnas);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            restaEntero.ptr[i][j] = m.ptr[i][j] - n;
        }
    }
    return restaEntero;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D multiEntero(m.filas, m.columnas);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            multiEntero.ptr[i][j] = m.ptr[i][j] * n;
        }
    }
    return multiEntero;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D diviEntero(m.filas, m.columnas);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            diviEntero.ptr[i][j] = m.ptr[i][j] / n;
        }
    }
    return diviEntero;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}