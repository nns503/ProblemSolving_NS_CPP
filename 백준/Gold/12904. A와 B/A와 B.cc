#include <bits/stdc++.h>

using namespace std;

string s, t;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	
	while(s.size() < t.size()){
		auto cur = t.back();
		t.pop_back();
		if(cur == 'B'){
			reverse(t.begin(), t.end());
		}
	}
	
	cout << (s==t?1:0); 
}