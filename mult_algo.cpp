#include <vector>
#include "mult_algo.h"
#define vi vector<int>
#define vvi vector<vi>


using namespace std;


void suma(vvi &a, vvi &b, vvi &resultado,
        int fila1, int columna1, int fila2, int columna2, int fila3, int columna3,
        int n, bool permanencia)
{
    /*
    Recibe 2 matrices 'a' y 'b' de tamaño 'n'x'n' y una matriz 'resultado'.
    Guarda la suma entre 'a' y 'b' desde las coordenadas especificadas en 'fila1', 'columna1',
    'fila2' y 'columna2' en 'resultado' desde la posición ('fila3', 'columna3').
    Si 'permanencia'=true entonces las suma entre 'a' y 'b' se suma a 'resultado' en vez de reemplazarlo.
    */
    int i, j;
    if(!permanencia)
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                resultado[fila3+i][columna3+j] = a[fila1+i][columna1+j]+b[fila2+i][columna2+j];
        }
    else
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                resultado[fila3+i][columna3+j] += a[fila1+i][columna1+j]+b[fila2+i][columna2+j];
        }
}

void resta(vvi &a, vvi &b, vvi &resultado,
        int fila1, int columna1, int fila2, int columna2, int fila3, int columna3,
        int n, bool permanencia)
{
    /*
    Recibe 2 matrices 'a' y 'b' de tamaño 'n'x'n' y una matriz 'resultado'.
    Guarda la diferencia entre 'a' y 'b' desde las coordenadas especificadas en 'fila1', 'columna1',
    'fila2' y 'columna2' en 'resultado' desde la posición ('fila3', 'columna3').
    Si 'permanencia'=true entonces las diferencia entre 'a' y 'b' se suma a 'resultado' en vez de reemplazarlo.
    */
    int i, j;
    if(!permanencia)
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                resultado[fila3+i][columna3+j] = a[fila1+i][columna1+j]-b[fila2+i][columna2+j];
        }
    else
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                resultado[fila3+i][columna3+j] += a[fila1+i][columna1+j]-b[fila2+i][columna2+j];
        }
}

void armar(vvi &p1, vvi &p2, vvi &p3, vvi &p4, vvi &p5, vvi &p6, vvi &p7,
        vvi &resultado, int fila, int columna, int n)
{
    /*
    Recibe 8 matrices desde 'p1' hasta 'p7' de tamaño ('n'/2)x('n'/2) y una matriz vacía 'resultado'.
    Arma la matriz de Strassen en 'resultado'.
    */

   int n_2 = n>>1;

   //p5+p4-p2+p6
   resta(p4, p2, resultado, 0, 0, 0, 0, fila, columna, n_2, false);
   suma(p5, p6, resultado, 0, 0, 0, 0, fila, columna, n_2, true);

   //p1+p2
   suma(p1, p2, resultado, 0, 0, 0, 0, fila, columna+n_2, n_2, false);

   //p3+p4
   suma(p3, p4, resultado, 0, 0, 0, 0, fila+n_2, columna, n_2, false);

   //p1+p5−p3−p7
   resta(p5, p3, resultado, 0, 0, 0, 0, fila+n_2, columna+n_2, n_2, false);
   resta(p1, p7, resultado, 0, 0, 0, 0, fila+n_2, columna+n_2, n_2, true);
}

void strassen(vvi &m1, vvi &m2, vvi &resultado,
            int fila1, int columna1, int fila2, int columna2, int fila3, int columna3, int n)
{
    if(n==1)
    {
        resultado[fila3][columna3] = m1[fila1][columna1]*m2[fila2][columna2];
        return;
    }
    int n_2 = n>>1;
    vvi aux(n_2, vi(n_2)), aux2(n_2, vi(n_2));
    vvi p1(n_2, vi(n_2)), p2(n_2, vi(n_2)), p3(n_2, vi(n_2));
    vvi p4(n_2, vi(n_2)), p5(n_2, vi(n_2)), p6(n_2, vi(n_2)), p7(n_2, vi(n_2));

    //aux = f-h
    resta(m2, m2, aux, fila2, columna2+n_2, fila2+n_2, columna2+n_2, 0, 0, n_2, false);
    //p1 = a*aux
    strassen(m1, aux, p1, fila1, columna1, 0, 0, 0, 0, n_2);

    //aux = a+b
    suma(m1, m1, aux, fila1, columna1, fila1, columna1+n_2, 0, 0, n_2, false);
    //p2 =  aux*h
    strassen(aux, m2, p2, 0, 0, fila2+n_2, columna2+n_2, 0, 0, n_2);

    //aux = c+d
    suma(m1, m1, aux, fila1+n_2, columna1, fila1+n_2, columna1+n_2, 0, 0, n_2, false);
    //p3 = aux*e
    strassen(aux, m2, p3, 0, 0, fila2, columna2, 0, 0, n_2);

    //aux = g-e
    resta(m2, m2, aux, fila2+n_2, columna2, fila2, columna2, 0, 0, n_2, false);
    //p4 = d*aux
    strassen(m1, aux, p4, fila1+n_2, columna1+n_2, 0, 0, 0, 0, n_2);

    //aux = a+d
    suma(m1, m1, aux, fila1, columna1, fila1+n_2, columna1+n_2, 0, 0, n_2, false);
    //aux2 = e+h
    suma(m2, m2, aux2, fila2, columna2, fila2+n_2, columna2+n_2, 0, 0, n_2, false);
    //p5 = aux1*aux2
    strassen(aux, aux2, p5, 0, 0, 0, 0, 0, 0, n_2);

    //aux = b-d
    resta(m1, m1, aux, fila1, columna1+n_2, fila1+n_2, columna1+n_2, 0, 0, n_2, false);
    //aux2 = g+h
    suma(m2, m2, aux2, fila2+n_2, columna2, fila2+n_2, columna2+n_2, 0, 0, n_2, false);
    //p6 = aux*aux2
    strassen(aux, aux2, p6, 0, 0, 0, 0, 0, 0, n_2);

    //aux = a-c
    resta(m1, m1, aux, fila1, columna1, fila1+n_2, columna1, 0, 0, n_2, false);
    //aux2 = e+f
    suma(m2, m2, aux2, fila2, columna2, fila2, columna2+n_2, 0, 0, n_2, false);
    //p7 = aux*aux2
    strassen(aux, aux2, p7, 0, 0, 0, 0, 0, 0, n_2);

    armar(p1, p2, p3, p4, p5, p6, p7, resultado, fila3, columna3, n);
}

void naive_mul(vvi &a, vvi &b, vvi &resultado,
            int fila1, int columna1, int fila2, int columna2,int fila3, int columna3, int n)
{
    int i, j, k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<n; k++)
                resultado[i+fila3][j+columna3] += a[i+fila1][k+columna1]*b[k+fila2][j+columna2];
}