#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{   
    int n, nr, m, ns; //constantes del problema
    int i, j, k; //valores auxiliares
    vector<vector<int>> r, s; // tablas
    vector<int> atributos_r, atributos_s; //nombres de los atributos de cada tabla

    //se obtiene la información y se llenan las tablas
    //R
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> j;
        atributos_r.push_back(j);
    }
    cin >> nr;
    for(i=0; i<nr; i++)
    {
        r.push_back(vector<int>()); //se introduce una fila
        for(j=0; j<n; j++)
        {
            cin >> k;
            r[i].push_back(k); //se llenan las columnas
        }
    }

    //S
    cin >> m;
    for(i=0; i<n; i++)
    {
        cin >> j;
        atributos_s.push_back(j);
    }
    cin >> ns;
    for(i=0; i<ns; i++)
    {
        r.push_back(vector<int>()); //se introduce una fila
        for(j=0; j<m; j++)
        {
            cin >> k;
            s[i].push_back(k); //se llenan las columnas
        }
    }

    return 0;
}
