/*
 * Developed by Erick Ignacio Santillan Zaragoza (Santirax)
 * Solucion del problema
 * Escalera, problema de OmegaUP 
 * https://omegaup.com/arena/problem/escalera/#problems
 */
#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector<long long>DP(1e6, -1);
//int ans = 0;

long long escalera(long long N){
  if(N == 0)return 1;
  if(N < 0)return 0;
  if(DP[N] != -1)return DP[N];
  long long ans = 0;
  for(long long i = 1; i <= K; i++){
    //cout<<N-i<<endl;
    ans += escalera(N-i);
    //cout<<escalera(N-K)<<endl;
    //cout<<N-K<<endl;
  }
  //cout<<ans<<endl;
  return DP[N] = ans;
}


int main (){
 cin>>N>>K;

 cout<<escalera(N)<<"\n";

  return 0;
}
