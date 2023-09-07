#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;
int sum;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	arr.push_back(sum);
	
	for(int i=0; i<n; i++){
		int a; 
		cin >> a;
		sum += a;
		arr.push_back(sum);
	}	
	
	cin >> m;
	
	while(m--){
		int st, en;
		cin >> st >> en;
		cout << arr[en] - arr[st-1] << '\n';
	}
	
	return 0;
}