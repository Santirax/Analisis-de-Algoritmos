#include <bits/stdc++.h>
using namespace std;

bool comparacion (pair<int, int>  a, pair<int, int > b){
    double p_v1 = (double)a.second / (double)a.first;
    double p_v2 = (double)b.second / (double)b.first;
    
    return p_v1 > p_v2;
}

int main (){
    
    //Donde el first es el peso y el second el valor
    vector< pair<int, int> > mochila;
    
    int peso = 50;
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        int w, val;
        cin>>w>>val;
        mochila.push_back({w,val});
    }
    
    //Comparacion por valor/peso
    sort(mochila.begin(), mochila.end(), comparacion);
    
    int pesoActual = 0;
    double max_valor = 0.0;
    
    for(int i = 0; i < mochila.size(); i++){
        if(pesoActual + mochila[i].first <= peso){
            pesoActual += mochila[i].first;
            max_valor += mochila[i].second;
        }else{
            double pesoRestante = peso - pesoActual;
            max_valor += (pesoRestante * mochila[i].second) / mochila[i].first;
            break;
        }
    }
    
    cout << max_valor << endl; 
    
    return 0;
}
