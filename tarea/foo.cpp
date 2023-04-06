#include "foo.h"

Matriz2D::Matriz2D(): filas(3), columnas(3) {
    // Constructor por defecto
    ptr = new int *[getFilas()];
    for (int i = 0; i < getFilas(); i++) {
        ptr[i] = new int[getFilas()];
    }
    for (int i = 0; i < getFilas(); i++) {
        for (int j = 0; j < getFilas(); j++) {
            ptr[i][j] = rand() % 1;
        }
    }
}

Matriz2D::Matriz2D(int n): filas(n),columnas(n){
    // Constructor con un parametro
    ptr = new int*[getFilas()];
    for(int i = 0; i < getFilas(); i++){
        ptr[i] = new int[getFilas()];
    }
    for(int i = 0; i < getFilas(); i++){
        for(int j = 0; j < getFilas(); j++){
            ptr[i][j] = rand() % 1;
        }
    }
}

Matriz2D::Matriz2D(int n, int m): filas(n), columnas(m){
    // Constructor con dos parametros
    ptr = new int*[getFilas()];
    for(int i = 0; i < getFilas(); i++){
        ptr[i] = new int[getColumnas()];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ptr[i][j] = rand() % 1;
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
        ptr = new int*[m.filas];
        for(int i = 0; i < m.filas; i++){
            ptr[i] = new int[m.columnas];
        }
        for(int i = 0; i < m.filas; i++){
            for(int j = 0; j < m.columnas; j++){
                ptr[i][j] = m[i][j];
            }
        }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    for(int i = 0; i < m.filas; i++){
        ptr[i] = new int[m.columnas];
    }
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            ptr[i][j] = m[i][j];
        }
    }
    m.ptr = nullptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D traspuesta(m.filas, m.columnas);
    for(int i = 0; i < m.columnas; i++){
        for(int j = 0; j < m.filas; j++){
            traspuesta.ptr[i][j] = m[j][i];
        }
    }
    return traspuesta;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for (int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            os << m[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D suma(m1.filas, m1.columnas);
    for (int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.columnas; j++){
            suma[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return suma;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D resta(m1.filas, m1.columnas);
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.columnas; j++){
            resta.ptr[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return resta;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D multiplicacion(m1.filas, m1.columnas);
    for(int i=0; i<m1.filas;i++){
        for(int j=0; j<m1.columnas; j++){
            multiplicacion[i][j] = m1[i][j] * m2[i][j];
        }
    }
    return multiplicacion;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D sumaEntero(m.filas, m.columnas);
    for(int i = 0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            sumaEntero[i][j] = m[i][j] + n;
        }
    }
    return sumaEntero;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D restaEntero(m.filas, m.columnas);
    for(int i = 0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            restaEntero[i][j] = m[i][j] - n;
        }
    }
    return restaEntero;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D multiEntero(m.filas, m.columnas);
    for(int i = 0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            restaEntero[i][j] = m[i][j] * n;
        }
    }
    return multiEntero;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D diviEntero(m.filas, m.columnas);
    for(int i = 0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            restaEntero[i][j] = m[i][j] / n;
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