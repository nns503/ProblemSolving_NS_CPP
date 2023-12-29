#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10001];
long long answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+n);
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int sum = arr[i] + arr[j];
			if(binary_search(arr+j+1, arr+n, -sum)){
				int low_idx = (lower_bound(arr+j+1, arr+n, -sum) - arr);
				int up_idx = (upper_bound(arr+j+1, arr+n, -sum) - arr);	
				answer += up_idx - low_idx;	
			}
		}
	} 
	cout << answer;
	return 0;
}
