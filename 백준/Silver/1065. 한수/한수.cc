#include <bits/stdc++.h>

using namespace std;

int n;
int answer;

bool func(int num){
	if(num <= 99) return true;
	
	string s = to_string(num);
	
	int d = s[1] - s[0];
	
	for(int i=2; i<s.size(); i++){
		if(d != s[i] - s[i-1]) return false;
	}
	
	return true;
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		if(func(i)) answer++;
	}
	
	cout << answer;
	
	return 0;
}
