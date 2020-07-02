#include <vector>
#include <iostream>
#include "mult_algo.h"
#define vi vector<int>
#define vvi vector<vi>


using namespace std;

void suma(vvi &a, vvi &b, vvi &resultado,
        int fila1, int columna1, int fila2, int columna2, int fila3, int columna3,
        int n, bool permanencia);

void strassen(vvi &m1, vvi &m2, vvi &resultado,
            int fila1, int columna1, int fila2, int columna2, int fila3, int columna3, int n);


int main()
{
    //caso (nxkn)*(knxn)
    
    //leer entrada
    int n, k, i, j;
    cin >> n >> k;
    vvi a(n, vi(k*n));
    vvi b(k*n, vi(n));
    vvi c(n, vi(n));
    vvi d(n, vi(n, 0));
    vvi e(n, vi(n, 0));
    for(i=0; i<n; i++)
        for(j=0; j<k*n; j++)
            cin >> a[i][j];
    for(i=0; i<k*n; i++)
        for(j=0; j<n; j++)
            cin >> b[i][j];

    for(i=0; i<k*n; i+=n)
    {
        strassen(a, b, c, 0, i, i, 0, 0, 0, n);
        suma(c, d, e, 0, 0, 0, 0, 0, 0, n, true);
    }
    cout << n << " " << n << endl;
    for(vector<vi>::iterator f=e.begin(); f!=e.end(); f++)
    {
        for(vector<int>::iterator g=f->begin(); g!=f->end(); g++)
            cout << *g << " ";
        cout << endl;
    }

    return 0;
}
