#include <bits/stdc++.h>

using namespace std;

int n;

void func(int len){
	if(len == 0) return;
	
	for(int i=0; i<n; i++){
		if(i < n - len) cout << ' ';
		else cout << '*';
	}
	cout << '\n';
	func(len - 1);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	func(n);	
	
	return 0;
}

