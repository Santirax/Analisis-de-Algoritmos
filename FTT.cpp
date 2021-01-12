/*
 *Developed by Erick Ignacio Santillan Zaragoza (Santirax)
 *Implementacion de la Transformada Rapida de Fourier
 */


#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using comp = complex<double>;
const double PI = acos(-1.0);

void fft(vector<comp> &a, int sign = +1){
	int n = a.size();

	for (int i = 1, j = 0; i < n - 1; ++i){
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
		if (i < j) swap(a[i], a[j]);
	}

	double theta = 2 * atan2(0, -1) * sign;

	for (int m, mh = 1; (m = mh << 1) <= n; mh = m){
		comp wm(cos(theta / m), sin(theta / m)), w(1, 0);

		for (int i = 0; i < n; i += m, w = comp(1, 0))
			for (int j = i, k = j + mh; j < i + mh; ++j, ++k, w = w * wm){
				comp x = a[j], y = a[k] * w;
				a[j] = x + y;
				a[k] = x - y;
			}
	}

	if (sign == -1)
		for (comp &p : a) p = p / (1. * n);
}




int main (){
    
    vector<comp> pol;
    pol.push_back(1);
    pol.push_back(2);
    pol.push_back(3);
    pol.push_back(4);
    pol.push_back(5);
    
    for(auto x: pol)cout<<x<<" ";
    cout<<endl;
    
    cout << "Transformada\n";
    fft(pol, 1);
    for(auto x: pol)cout<<x<<" ";
    cout << endl;
    
    cout << "Transformada inversa\n";
    fft(pol, -1);
    for(auto x: pol)cout<<x<<" ";
    cout << endl;
    
    
    
    return 0;
}
