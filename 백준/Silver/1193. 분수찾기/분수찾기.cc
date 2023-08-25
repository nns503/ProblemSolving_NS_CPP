#include <bits/stdc++.h>

using namespace std;

int x, d, n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x;
	int p = 1;	
	while(x - p > 0){
		x -= p;
		p++;
	}
	
	// 분모 
	if(p % 2){
		d = p;
		n = 1;
		while(x > 1){
			d--;
			n++;
			x--;
		}
	}
	else{
		d = 1;
		n = p;
		while(x > 1){
			d++;
			n--;
			x--;
		}
	}
	
	cout << d << '/' << n;
	
	return 0;
}