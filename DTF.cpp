/*

Developed by Erick Ignacio Santillan Zaragoza (Santirax)
Implementación de la transformada discreta de Fourier

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

 A.push_back(2);
 A.push_back(5);
 A.push_back(3);
 A.push_back(8);

 ll a = esCero(cos( (2*PI)/A.size()) );
 ll bi = esCero( sin((2*PI)/A.size()) );
 complejo w = complejo(a, bi);
 cout<<"W = "<<w<<endl;

 //at_k = sumatoria de j=0 a n-1, de (W^k)^j * a_j 
 //Donde k es el subindice
 //n el tamaño del arreglo
 // W = e^((2*PI*i)/n)          *NOTA: El i es de la unidad imaginaria
 // W son las raices de la unidad Z^n = 1

 complejo aux = complejo(0, 0);
 for(int k = 0; k < A.size(); k++){
   for(int j = 0; j <= A.size()-1; j++){
    aux += ( pow(w , (k*j)%4 ) * A[j] );
   }
  At.push_back(aux);
  aux = complejo(0, 0);
 }

 cout<<"At: \n";
 for(int k = 0; k < At.size(); k++){
  cout<<"At_"<<k<<" = "<<At[k]<<endl;
 }



 return 0;
}
