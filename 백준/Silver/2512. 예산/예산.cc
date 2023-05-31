#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		arr.push_back(a);
	}
	cin >> m;
	
	sort(arr.begin(), arr.end());
	
	answer = arr.back();
	
	for(int i=0; i<arr.size(); i++){
		if(arr[i] * (arr.size() - i) <= m){
			m -= arr[i];
			continue;
		}
		answer = m / (arr.size() - i);
		break;	
	}
	
	cout << answer;
	
	return 0;
}

