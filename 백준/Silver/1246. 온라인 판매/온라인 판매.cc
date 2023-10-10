#include <bits/stdc++.h>

using namespace std;

int n, m, answer, p;
vector<int> arr;


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a; cin >> a;
		arr.push_back(a);
	}
	
	sort(arr.begin(), arr.end(), greater<int>());
	
	
	for(int i=0; i<m; i++){
		int cur = 0;
		
		if(i < n) cur = arr[i] * (i+1);
		else cur = arr[i] * n;
		
		if(answer <= cur){
			answer = cur;
			p = arr[i];
		}
	}
	
	cout << p << ' ' << answer;

	return 0;
}
