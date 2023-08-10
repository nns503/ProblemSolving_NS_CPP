#include <bits/stdc++.h>

using namespace std;

int n;
long long answer;
long long f[1000001];
long long g[1000001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=1; i<=1000000; i++){
		for(int k=1; i*k<=1000000; k++){
			f[i*k] += i; 
		}
	}
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		answer += f[i];
	}
	
	cout << answer;
	
	return 0;
}
