/*

Developed by Erick Ignacio Santillan Zaragoza (Santirax)
Implementacion del merge sort

*/

#include <iostream>
using namespace std;

typedef long long int lli;
typedef  const long long int Clli;

void combinar (lli A[], lli p, lli q, lli r) /*Funcion Merge, le pasamos el arreglo, el indice p -> principio del arreglo, q -> la mitad del arreglo, r -> el final del arreglo*/
{
    Clli P = 10000000; //Centinela para el limite del arreglo sumponiendo que vamos a manejar numero menores que 10^7
    lli n1 = q - p + 1; //Definimos el tamaño del arreglo izquierdo restando al indice de en medio el indice del principio mas 1
    lli n2 = r - q; //Definimos el tamaño del arreglo derecho restando al indice final, el de en medio

    lli L[n1+2]; //Declaracion del arreglo izquierdo
    lli R[n2+2]; //Declaracion del arreglo derecho

    //Copiar a izquiero
    for(lli i = 1; i<=n1; i++)
    {
        L[i] = A[p+i-1];
    }

    //Copiar a derecho
    for(lli i = 1; i<=n2; i++)
    {
        R[i] = A[q+i];
    }

    L[n1+1] = P; //Declaracion del centinela en el arreglo
    R[n2+1] = P; //Declaracion del centinela en el arreglo, como el infinito del Corman


    //Esto es lo que hace la funcion de combinar izquierdo y derecho
    for(lli k = p/*k al principio del arreglo, controla A*/, i = 1/*Para recorrer lado izquierdo*/, j = 1/*recorrer derecho*/; k <= r/*Hasta que se recorra todo el arreglo*/; k++)
    {

        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }

    }

}

void Ordenar (lli A[], lli p, lli r)
{
    //cout<<"En el if";
    if(p < r)
    {
        lli q = ((p+r)/2);
        Ordenar (A, p, q);
        Ordenar (A, q+1, r);
        combinar(A, p, q, r);
    }
}

int main (){
    lli A[8];

    A[1] = 39;
    A[2] = 80;
    A[3] = 29;
    A[4] = 3;
    A[5] = 9;
    A[6] = 2;
    A[7] = 78;

    lli p = 1, q = 4, r = 7;

    Ordenar(A, p, r);
    cout<<"Impresion del arreglo:\n";
    for(int i = 1; i<8; i++)
        cout<<A[i]<<" ";

    return 0;

}
