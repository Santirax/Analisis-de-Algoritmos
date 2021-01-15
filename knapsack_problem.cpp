/* Implementacion del problema de la mochila, en el link
 * 
 * https://www.spoj.com/problems/KNAPSACK/
 */
#include <bits/stdc++.h>
using namespace std;


vector< vector<int> > DP (2100, vector<int>(2100, -1));
vector< pair<int, int> > mochila;


int llenarMochila(int peso, int i){
    
    if(i == 0 || peso == 0) return 0;
    
    if(DP[peso][i] != -1) return DP[peso][i];
        
    if(mochila[i-1].first > peso) return DP[peso][i] = llenarMochila(peso, i-1);
    
    return DP[peso][i] = max( mochila[i-1].second + llenarMochila(peso-mochila[i-1].first, i-1), llenarMochila(peso, i-1) );
    
}

int main(){
    
    int peso, n;
    
    cin>>peso>>n;
    
    for(int i = 0; i < n; i++){
        int w, val;
        cin>>w>>val;
        mochila.push_back({w, val});
    }

    cout << llenarMochila(peso, mochila.size()) << endl;
    
    return 0;
}
