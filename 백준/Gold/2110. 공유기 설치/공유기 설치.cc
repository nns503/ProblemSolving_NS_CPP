#include <bits/stdc++.h>

using namespace std;

int n, c;
int answer;
vector<int> arr;

int func(int len){
	int cnt = 1;
	int prev = arr[0];
	for(int i=1; i<n; i++){
		if(arr[i] - prev >= len){
			cnt++;
			prev = arr[i];
		}
	}
	return cnt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c;
	
	for(int i=0; i<n; i++){
		int a; cin >> a; arr.push_back(a);
	}	
	
	sort(arr.begin(), arr.end());
	
	int l = 0;
	int r = arr[n-1];
	while(l <= r){
		int mid = (l+r)/2;
		int cnt = func(mid);
		if(c <= cnt){
			answer = mid;
			l = mid + 1;
		}
		else if(c > cnt){
			r = mid - 1;
		}
	}
	
	cout << answer;
	
	return 0;
}