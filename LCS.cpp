/*
   Developed by Erick Ignacio Santillan Zaragoza (Santirax)
   Implementacion del problema Longest Common Subsequence
   En el link:
   https://leetcode.com/problems/longest-common-subsequence/
 */
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
vector<vector<int>> DP(1100, vector<int>(1100, -1)); 

//Version con indices desde size()-1
int lcs(int i, int j){
    
    if(i == -1 || j == -1) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    
    if(s1[i] == s2[j]) return DP[i][j] = 1 + lcs(i-1, j-1);
    
    return DP[i][j] = max( lcs(i, j-1), lcs(i-1, j) );
}

//Version con indices  desde size()
/*
int lcs(int i, int j){
    
    if(i == 0 || j == 0) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    
    if(s1[i-1] == s2[j-1]) return DP[i][j] = 1 + lcs(i-1, j-1);
    
    return DP[i][j] = max( lcs(i, j-1), lcs(i-1, j) );
}
*/

int main (){
    
    cin>>s1>>s2;
    cout << lcs (s1.size()-1, s2.size()-1) << endl;
    
    return 0;
}
