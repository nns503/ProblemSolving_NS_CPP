#include <bits/stdc++.h>

using namespace std;

int a1, a2;
int b1, b2;
int c1, c2;

int GCD(int a, int b){
	if(a % b == 0) return b;
	else return GCD(b, a % b);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a1 >> a2;
	cin >> b1 >> b2;
		
	c1 = a1 * b2 + a2 * b1;
	c2 = a2 * b2;
	
	while(true){
		int gcd = GCD(c2, c1);
		if(gcd == 1) break;
		c1 /= gcd; 
		c2 /= gcd;
	}
	
	cout << c1 << ' ' << c2;
	return 0;
}