#include <bits/stdc++.h>

using namespace std;

set<int> s;
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		s.insert(a);
	}	
	
	for(auto n : s){
		cout << n << ' ';
	}
	
	return 0;
}