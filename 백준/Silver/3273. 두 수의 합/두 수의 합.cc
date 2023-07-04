#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<int> arr;
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		arr.push_back(a);
	}
	
	cin >> x;
	
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<n-1; i++){
		int cur = x - arr[i]; 
		if(binary_search(arr.begin() + i + 1, arr.end(), cur)) answer++;
	}
	cout << answer;
	return 0;
}