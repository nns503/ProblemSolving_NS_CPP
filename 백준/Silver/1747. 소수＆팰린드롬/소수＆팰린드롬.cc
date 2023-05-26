#include <bits/stdc++.h>
#define MAX 3000000
using namespace std;

int n;
bool m[MAX]; 
bool vis[MAX]; 
bool ans[MAX]; 

bool PD(int num){
	string s = to_string(num);
	for(int i=0; i<s.size()/2; i++){
		if(s[i] != s[s.size() - i - 1]) return false;
	}
	return true;
}

int main(void){
	
	// 에레토스테네스의 체 
	cin >> n;
	
	vis[1] = true;
	for(int i=2; i<=MAX; i++){
		if(vis[i]) continue;
	
		ans[i] = PD(i);	
		for(int j=i; j<=MAX; j+=i){
			vis[j] = true;
		}
	}
	
	for(int i=n; i<=MAX; i++){
		if(ans[i]){
			cout << i;
			return 0;
		}
	}
}