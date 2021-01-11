/*
 Developed by Erick Ignacio Santillan Zaragoza (Santirax)
 Implementacion del algoritmo de Karatsuba
*/

#include <iostream>
using namespace std;
typedef long long int ll;
/*string operator * (const string & s1, const string & s2) {
    return s1+s2;
    
};*/

string addZeros(string number, int numZeros, bool left = true){
    for(int i = 0; i < numZeros; i++){
        if(left){
            number = '0' + number;
        }else{
            number = number + '0';
        }
    }
    return number;
}


string karatsuba(const string & a, const string & b){
    
    if(a.size() <= 9 and b.size() <= 9){ //Caso base cuando tengo un numero de 9 digitos o menos
        return to_string( stol(a)*stol(b) ); //Multiplicacion constante y la paso a string
    }
    
    //Relleno de zeros
    if(a.size() > b.size()){
        b = addZeros(b, a.size()-b.size());
    }else if(b.size() > a.size()){
        a = addZeros(a, b.size()-a.size());
    }
    
    ll n = a.size();
    ll j = n/2;
    
    if(n % 2 != 0)j++; //Impar
    
    BZeroPadding = n-j;
    AZeroPadding = 2*BZeroPadding;
    
    string xr = a.substr(0, j);
    string xl = a.substr(j, a.size()-1);
    
}

int main (){
    
    string a, b;
    cin>>a;
    cin>>b;
    
    cout<<karatsuba(a,b)<<endl; 
    
    return 0;
}
