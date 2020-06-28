#ifndef MULT_ALGO_H
#define MULT_ALGO_H
#include <vector>
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

void suma(vvi &a, vvi &b, vvi &resultado,
        int fila1, int columna1, int fila2, int columna2, int fila3, int columna3,
        int n, bool permanencia);

void resta(vvi &a, vvi &b, vvi &resultado,
        int fila1, int columna1, int fila2, int columna2, int fila3, int columna3,
        int n, bool permanencia);

void armar(vvi &p1, vvi &p2, vvi &p3, vvi &p4, vvi &p5, vvi &p6, vvi &p7, vvi &resultado, int n);

void strassen(vvi &m1, vvi &m2, vvi &resultado,
            int fila1, int columna1, int fila2, int columna2, int fila3, int columna3, int n);

void naive_mul(vvi &a, vvi &b, vvi &resultado, int n);
    

#endif