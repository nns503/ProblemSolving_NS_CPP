#include <bits/stdc++.h>

using namespace std;
int T,n;
int stock[1000001];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> stock[i];
		}
		long long answer = 0;
		int mx = stock[n-1];
		for(int i = n-2; i>=0; i--){
			if(mx>stock[i]){
				answer += mx - stock[i];
			}
			else{
				mx = stock[i];
			}
		}
		cout << answer << '\n';
	}
	return 0;
}