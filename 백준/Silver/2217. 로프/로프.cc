#include <bits/stdc++.h>

using namespace std;

int n;
int loop[100000];
int w[100000];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> loop[i];
	
	sort(loop, loop+n);
	
	for(int i=0; i<n; i++){
		w[i] = loop[i] * (n-i);
	}
	
	sort(w, w+n);
	
	cout << w[n-1];
	
	return 0;
}