#include <bits/stdc++.h>

using namespace std;

int n, m;
int answer;
int six = 1001, one = 1001;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1; i<=m; i++){
		int a, b;
		cin >> a >> b;
		if(six > a) six = a;
		if(one > b) one = b;
	}	
	
	if(six > one * 6) six = one * 6;
	
	if((n+5)/6 * six > n % 6 * one + n / 6 * six){
		cout << n % 6 * one + n / 6 * six ;
	}  
	else cout << (n+5)/6 * six;

	return 0;
}