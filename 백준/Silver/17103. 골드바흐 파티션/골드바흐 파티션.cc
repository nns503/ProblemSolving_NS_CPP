#include <bits/stdc++.h>

using namespace std;

bool p[1000001];
int num[1000001];
vector<int> arr;
int T, n;
	
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=2; i<=1000000; i++){
		if(p[i]) continue;
		arr.push_back(i);
		for(int j=i+i; j<=1000000; j+=i){
			p[j] = true;
		}
	}	
	
	cin >> T;
	
	while(T--){
		cin >> n;
		int answer = 0;
		for(int i=0; i<arr.size() && n - arr[i] > 1; i++){
			if(!p[n - arr[i]]){
				answer++;
			}
		}
		cout << (answer % 2 ? answer/2 + 1 : answer/2)  << '\n';
		
	}
	return 0;
}
