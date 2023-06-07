#include <bits/stdc++.h>

using namespace std;

int n, m;
int answer = 10000;
vector<int> arr;

int func(int len){
	int cnt = 1;
	int sum = arr[0];	
	for(int i=1; i<n; i++){
		if(sum + arr[i] > len){
			sum = arr[i];
			cnt++;
		}
		else sum += arr[i];
	}
	return cnt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int a; cin >> a; arr.push_back(a);
	}
	
	int l = *max_element(arr.begin(), arr.end());
	int r = 0x3f3f3f3f;
	
	while(l <= r){
		int mid = (l + r)/2;
		int cnt = func(mid);
		if(cnt <= m){
			answer = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	
	cout << answer;
	
	return 0;
}