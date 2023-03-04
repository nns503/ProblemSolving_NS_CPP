#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return a==0?b:gcd(b%a, a);
}

int lcm(int a, int b){
	return a/gcd(a, b)*b;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, m, n, x, y;
	cin >> T;
	while(T--){
		int chk = true;
		cin >> m >> n >> x >> y;
		if(x==m) x=0;
		if(y==n) y=0;
		int len = lcm(m, n);
		for(int i=x; i<=len; i+=m){
			if(i == 0) continue;
			if(i%n==y){
				cout << i << '\n';
				chk = false;
				break;
			}
		}
		if(chk) cout << -1 << '\n';
	}
	return 0;
}