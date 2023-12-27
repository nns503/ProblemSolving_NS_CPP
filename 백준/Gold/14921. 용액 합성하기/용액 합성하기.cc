#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
int answer = 0x3f3f3f3f;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		arr.push_back(a); 
	}

	for(int i=0; i<arr.size()-1; i++){
		int idx = (lower_bound(arr.begin()+i+1, arr.begin() + arr.size(), -arr[i]) - arr.begin());
		for(int k=-1; k<=0; k++){
			if(idx + k <= i || idx + k >= arr.size()) continue;
			if(abs(answer) > abs(arr[idx + k] + arr[i])){
				answer = arr[idx + k] + arr[i];
			}
		} 
	}
	
	cout << answer;
	
	return 0;
}