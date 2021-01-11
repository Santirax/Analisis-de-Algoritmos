/*

Developed by Erick Ignacio Santillan Zaragoza (Santirax)
Implementación de la transformada inversa discreta de Fourier

*/

#include <bits/stdc++.h>
#define PI 3.141592653589793238462643383279
#define ZERO 1e-10
using namespace std;

typedef long double ld;
typedef long long ll;
typedef complex<ld> complejo;
typedef vector<ll> vll;
typedef vector<complejo> v_comp;

ll esCero(ll a){
 if(abs(a) < ZERO)return 0;
 else return a;
}

int main (){

 v_comp  A, At;

 At.push_back(complejo(12,0));
 At.push_back(complejo(1,1));
 At.push_back(complejo(6,0));
 At.push_back(complejo(1,-1));
 
 ll a = esCero(cos( (2*PI)/At.size()) );
 ll bi = esCero( sin((2*PI)/At.size()) );
 complejo w = complejo(a, bi);
 cout<<"W = "<<w<<endl;

 //a_k = 1/n (sumatoria de j=0 a n-1, de (W^-k)^j * at_j) 
 //Donde k es el subindice
 //n el tamaño del arreglo
 // W = e^((2*PI*i)/n)          *NOTA: El i es de la unidad imaginaria
 // W son las raices de la unidad Z^n = 1

 complejo aux = complejo(0, 0);
 for(int k = 0; k < At.size(); k++){
   for(int j = 0; j <= At.size()-1; j++){
    aux += ( pow(w , (-k*j)%4 ) * At[j] );
   }
  complejo tam = complejo(At.size(), 0);
  A.push_back(aux/tam);
  aux = complejo(0, 0);
 }

 cout<<"At: \n";
 for(int k = 0; k < A.size(); k++){
  cout<<"A_"<<k<<" = "<<A[k]<<endl;
 }


 return 0;
}
