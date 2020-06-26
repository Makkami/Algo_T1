#include <vector>
#include <iostream>
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

vvi p1(512, vi(512)), p2(512, vi(512)), p3(512, vi(512));
vvi p4(512, vi(512)), p5(512, vi(512)), p6(512, vi(512)), p7(512, vi(512));

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
    if(permanencia)
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
    if(permanencia)
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

void armar(vvi &p1, vvi &p2, vvi &p3, vvi &p4, vvi &p5, vvi &p6, vvi &p7, vvi &resultado, int n)
{
    /*
    Recibe 8 matrices desde 'p1' hasta 'p7' de tamaño 'n'x'n' y una matriz vacía 'resultado'.
    Arma la matriz de Strassen en 'resultado'.
    */

   //p5+p4-p2+p6
   resta(p4, p2, resultado, 0, 0, 0, 0, 0, 0, n, true);
   suma(p5, p6, resultado, 0, 0, 0, 0, 0, 0, n, false);

   //p1+p2
   suma(p1, p2, resultado, 0, 0, 0, 0, 0, n>>1, n, true);

   //p3+p4
   suma(p3, p4, resultado, 0, 0, 0, 0, n>>1, 0, n, true);

   //p1+p5−p3−p7
   resta(p5, p3, resultado, 0, 0, 0, 0, n>>1, n>>1, n, true);
   resta(p1, p7, resultado, 0, 0, 0, 0, n>>1, n>>1, n, false);
}

void strassen(vvi &m1, vvi &m2, vvi &resultado,
            int fila1, int columna1, int fila2, int columna2, int fila3, int columna3, int n)
{
    if(n==1)
    {
        resultado[0][0] = m1[0][0]*m2[0][0];
        return;
    }
    int n_2 = n>>1;
    vvi aux(n_2, vi(n_2)), aux2(n_2, vi(n_2));

    //aux = f-h
    resta(m2, m2, aux, 0, n_2, n_2, n_2, 0, 0, n_2, true);
    //p1 = a*aux
    strassen(m1, aux, p1, 0, 0, 0, 0, 0, 0, n_2);

    //aux = a+b
    suma(m1, m1, aux, 0, 0, 0, n_2, 0, 0, n_2, true);
    //p2 =  aux*h
    strassen(aux, m2, p2, 0, 0, n_2, n_2, 0, 0, n_2);

    //aux = c+d
    suma(m1, m1, aux, n_2, 0, n_2, n_2, 0, 0, n_2, true);
    //p3 = aux*e
    strassen(aux, m2, p3, 0, 0, 0, 0, 0, 0, n_2);

    //aux = g-e
    resta(m2, m2, aux, n_2, 0, 0, 0, 0, 0, n_2, true);
    //p4 = d*aux
    strassen(m1, aux, p4, n_2, n_2, 0, 0, 0, 0, n_2);

    //aux = a+d
    suma(m1, m1, aux, 0, 0, n_2, n_2, 0, 0, n_2, true);
    //aux2 = e+h
    suma(m2, m2, aux2, 0, 0, n_2, n_2, 0, 0, n_2, true);
    //p5 = aux1*aux2
    strassen(aux, aux2, p5, 0, 0, 0, 0, 0, 0, n_2);

    //aux = b-d
    resta(m1, m1, aux, 0, n_2, n_2, n_2, 0, 0, n_2, true);
    //aux2 = g+h
    suma(m2, m2, aux2, n_2, 0, n_2, n_2, 0, 0, n_2, true);
    //p6 = aux*aux2
    strassen(aux, aux2, p6, 0, 0, 0, 0, 0, 0, n_2);

    //aux = a-c
    resta(m1, m1, aux, 0, 0, n_2, 0, 0, 0, n_2, true);
    //aux2 = e+f
    suma(m2, m2, aux2, 0, 0, 0, n_2, 0, 0, n_2, true);
    //p7 = aux*aux2
    strassen(aux, aux2, p7, 0, 0, 0, 0, 0, 0, n_2);

    armar(p1, p2, p3, p4, p5, p6, p7, resultado, n);

}
int main(int argc, char const *argv[])
{
    vvi a = {{1, 2}, {3, 4}};
    vvi b = {{1, 2}, {3, 4}};
    vvi c(2, vi(2));
    //strassen(a, b, c, 0, 0, 0, 0, 0, 0, 2);
    resta(a, b, c, 0, 0, 0, 0, 0, 0, 2, true);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}
