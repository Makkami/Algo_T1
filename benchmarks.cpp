#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <cmath>
#include "mult_algo.h"
#define vi vector<int>
#define vvi vector<vi>


using namespace std;
using namespace std::chrono;

void p3_2(vvi &a, vvi &b, vvi &c, vvi &d, vvi &e, int n, int k)
{
    int i;
    for(i=0; i<k*n; i+=n)
    {
        strassen(a, b, c, 0, i, i, 0, 0, 0, n);
        suma(c, d, e, 0, 0, 0, 0, 0, 0, n, true);
    }
}

void p3_2_naive(vvi &a, vvi &b, vvi &c, vvi &d, vvi &e, int n, int k)
{
    int i;
    for(i=0; i<k*n; i+=n)
    {
        naive_mul(a, b, c, 0, i, i, 0, 0, 0, n);
        suma(c, d, e, 0, 0, 0, 0, 0, 0, n, true);
    }
}

void random_matrix(vvi &a, vvi &b, int n, int k)
{
    //a(n,kn)
    //b(kn, n)

    int i, j;
    for(i=0; i<n*k; i++)
        for(j=0; j<n; j++)
        {
            a[j][i] = random()%101;
            b[i][j] = random()%101;
        }
}

int main()
{
    srand((unsigned)NULL);
    
    int k, i, j;
    for(k=2; k<=4; k++)
    {
        cout << "k=" << k << endl;
        for(i=2; i<=10; i++)
        {
            
            int n = pow(2, i);
            vvi a(n, vi(k*n)), b(k*n, vi(n));
            
            random_matrix(a, b, n, k);
            
            vvi c(n, vi(n)), d(n, vi(n, 0)), e(n, vi(n, 0));
            auto inicio = std::chrono::high_resolution_clock::now();
            p3_2(a, b, c, d, e, n, k);
            auto fin = std::chrono::high_resolution_clock::now();
            auto duracion = std::chrono::duration_cast<microseconds>(fin-inicio);
            
            for(j=0; j<n; j++)
            {
                fill(c[j].begin(), c[j].end(), 0);
                fill(d[j].begin(), d[j].end(), 0);
                fill(e[j].begin(), e[j].end(), 0);
            }

            auto inicio2 = std::chrono::high_resolution_clock::now();
            p3_2_naive(a, b, c, d, e, n, k);
            auto fin2 = std::chrono::high_resolution_clock::now();
            auto duracion2 = std::chrono::duration_cast<microseconds>(fin2-inicio2);

            cout << "s=" << duracion.count() << endl;
            cout << "n=" << duracion2.count() << endl;
        }
        cout << endl;
    }


    return 0;
}
