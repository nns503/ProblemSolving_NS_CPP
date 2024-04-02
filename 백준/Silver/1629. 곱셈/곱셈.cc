#include <bits/stdc++.h>

using namespace std;

int multi(long long a, long long b, long long c){
	if(b==1) return a%c;
	else{
		long long n = multi(a,b/2,c);
		n = n*n%c;
		if(b%2==0) return n;
		else return (n*a%c);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << multi(a,b,c);
	return 0;
}