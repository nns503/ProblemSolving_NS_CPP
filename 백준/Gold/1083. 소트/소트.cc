#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int n, s;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++){
		int a; cin >> a; arr.push_back(a);
	}
	cin >> s;
	
	for(int i=0; i<n-1; i++){
		int cur = i;
		for(int k=i+1; k<n; k++){
			if(k - i > s) break;
			if(arr[cur] < arr[k]){
				cur = k;
			}
		}
		
		s -= cur - i;
		
		for(int k=cur; k>i; k--){
			int temp = arr[k];
			arr[k] = arr[k-1];
			arr[k-1] = temp;
		}
		
	}
	
	for(int i=0; i<n; i++){
		cout << arr[i] << ' ';
	}
}