#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int a; cin >> a;
		arr.push_back(a);
	}	
	
	bool chk = next_permutation(arr.begin(), arr.end());
	
	if(chk){
		for(auto a : arr){
			cout << a << ' ';
		}
	}
	else cout << -1;
}

