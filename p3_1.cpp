#include <vector>
#include <iostream>
#include "mult_algo.h"
#define vi vector<int>
#define vvi vector<vi>


using namespace std;


void strassen(vvi &m1, vvi &m2, vvi &resultado,
            int fila1, int columna1, int fila2, int columna2, int fila3, int columna3, int n);

int main()
{
    //caso (knxn)*(nxkn)
    
    //leer entrada
    int n, k, i, j;
    cin >> n >> k;
    vvi a(n*k, vi(n));
    vvi b(n, vi(n*k));
    vvi c(n*k, vi(n*k));
    for(i=0; i<k*n; i++)
        for(j=0; j<n; j++)
            cin >> a[i][j];
    for(i=0; i<n; i++)
        for(j=0; j<n*k; j++)
            cin >> b[i][j];

    for(i=0; i<k*n; i+=n)
        for(j=0; j<k*n; j+=n)
            strassen(a, b, c, i, 0, 0, j, i, j, n);

    cout << k*n << " " << k*n << endl;
    for(vector<vi>::iterator d=c.begin(); d!=c.end(); d++)
    {
        for(vector<int>::iterator e=d->begin(); e!=d->end(); e++)
            cout << *e << " ";
        cout << endl;
    }

    return 0;
}
