#include <bits/stdc++.h>

using namespace std;

int n;

void func_1(int len){
	if(len == 0) return;
	
	for(int i=1; i<len; i++){
		cout << ' ';
	}
	for(int i=0; i<(n-len)*2+1; i++){
		cout << '*';
	}
	cout << '\n';
	
	func_1(len - 1);
}


void func_2(int len){
	if(len == 0) return;
	
	for(int i=0; i<n-len; i++){
		cout << ' ';
	}
	for(int i=0; i<len*2-1; i++){
		cout << '*';
	}
	cout << '\n';
	
	func_2(len - 1);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	func_1(n);	
	func_2(n-1);	
	return 0;
}

