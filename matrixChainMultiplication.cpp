/*
Implementacion del algoritmo matrix chain multiplication
*/
#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > DP(200, vector<int>(200, -1));
vector<int> matrices; 

int matrixChain(int i, int j){

    if(i == j) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    
    DP[i][j] = 1e6;
    for(int k = i; k < j; k++){
        DP[i][j] = min(DP[i][j], matrixChain(i, k) + matrixChain(k+1, j) + matrices[i-1] * matrices[k] * matrices[j]);
    }
    
    return DP[i][j];
}


int main(){
    
    matrices = {1, 2, 3, 4};
    
    cout << matrixChain (1, matrices.size()-1) << endl;


    return 0;
}
