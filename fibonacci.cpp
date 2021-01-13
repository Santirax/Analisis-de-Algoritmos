/*
 *Developed by Erick Ignacio Santillan Zaragoza (Santirax) 
 *Calcular un numero de fibonacci usando DP 
*/

#include <bits/stdc++.h>
using namespace std;

long long fibo(int n){
    vector<long long> DP(n+1, 0);
    if(n == 0)return 0;
    if(n == 1)return 1;
    
    DP[0] = 0;
    DP[1] = 1;
    
    for(long long i = 2; i <= n; i++){
        DP[i] = DP[i-1] + DP[i-2]; 
    }
    return DP[n];
    
}


int main (){
    int n; cin>>n;
    cout << fibo(n) << endl;
    return 0;
}
