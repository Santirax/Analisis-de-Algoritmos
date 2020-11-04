#include <iostream>
using namespace std;

typedef long long int lli;
typedef  const long long int Clli;

void combinar (lli A[], lli p, lli q, lli r) {
    Clli P = 1100000000000000000; 
    lli n1 = q - p + 1;
    lli n2 = r - q; 
    
    lli L[n1+2]; 
    lli R[n2+2]; 
    
    for(lli i = 1; i<=n1; i++){
        L[i] = A[p+i-1];
    }

    for(lli i = 1; i<=n2; i++){
        R[i] = A[q+i];
    }

    L[n1+1] = P;
    R[n2+1] = P;
    
    for(lli k = p, i = 1, j = 1; k <= r; k++){

        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }

    }

}

void Ordenar (lli A[], lli p, lli r){
    
    if(p < r){
        lli q = ((p+r)/2);
        Ordenar (A, p, q);
        Ordenar (A, q+1, r);
        combinar(A, p, q, r);
    }
}

int main (){
    
    lli n;
    lli T; 
    
    cin>>n>>T;
    
    lli A[n+1];
    
    for(int i = 1; i <= n; i++){
        cin>>A[i];
    }

    lli p = 1, r = n;

    Ordenar(A, p, r);
    
    /*cout<<"Impresion del arreglo:\n";
    for(int i = 1; i <= n; i++)
        cout<<A[i]<<" ";*/
    /*La solucion es sencilla, ordenas, de menor a mayor.
     * Vas tomando los menores
     * Mientras no supere al T que nos dan
     * Y cuando lo supera, cortas e imprimes lo que quedo
      */
    
    lli suma = 0; lli res = 0;
    for(int i = 1; i <= n; i++){
        if((suma + A[i]) > T){
            break;
        }else{
            suma += A[i];
            res++;
        }
        
    }
    
    cout << res << endl;
    
    return 0;

}
