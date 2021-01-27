/* Implementacion de la solucion al problema de seleccion de actividades */
#include<bits/stdc++.h>
 using namespace std;
 
 bool sortSecond(pair<int, int> & x, pair<int, int> & y){
     return x.second < y.second;
 }
 
 int main(){
     
     int n; cin >> n; 
     
     vector<pair<int, int>> activities;
     
     for(int i = 0; i < n; i++){
         int start, fin; cin>>start>>fin;
         activities.push_back({start, fin});
     }
     
     sort(activities.begin(), activities.end(), sortSecond);
     
     vector< pair<int, int> >  res = {activities[0]};
     
     for(int i = 1; i < n; i++){
         if( activities[i].first >= res[res.size()-1].second){
             //push a res y actualizo current
             res.push_back(activities[i]);
         }
     }
     
     cout << res.size() << endl;
     for(auto x: res){
         cout << x.first << " " << x.second <<"\n"; 
     }
     
 return 0;
 }
