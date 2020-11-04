/*

Developed by Erick Ignacio Santillan Zaragoza (Santirax)
Solucion del problema 12083. Pachito y sus tareas, mood Competitive
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main (){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n, T;
    cin>>n>>T;
    vector<ll>vec(n);
    
    for(ll & x: vec){
        cin>>x;
    }
    
    sort(vec.begin(), vec.end());
    
    ll suma = 0; ll res = 0;
    for(int i = 0; i < n; i++){
        if((suma+vec[i]) > T){
            break;
        }else{
            suma += vec[i];
            res++;
        }
    }
    
    cout << res << "\n";
    
    return 0;
}
