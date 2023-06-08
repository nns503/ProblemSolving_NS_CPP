#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
int a[1001];
int b[1001];
int dp[1001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int z; cin >> z; arr.push_back(z);
	}
	
	fill(a, a+n, 1); fill(b, b+n, 1);
	
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[j] < arr[i] && a[j] + 1 > a[i]){
				a[i] = a[j] + 1;
			}
		} 
	}
	
	for(int i=n-2; i>=0; i--){
		for(int j=n-1; j>i; j--){
			if(arr[j] < arr[i] && b[j] + 1 > b[i]){
				b[i] = b[j] + 1;
			}
		} 
	}
	
	for(int i=0; i<n; i++){
		dp[i] = a[i] + b[i] - 1;
	}
	
	cout << *max_element(dp, dp+n);
	
	return 0;
}