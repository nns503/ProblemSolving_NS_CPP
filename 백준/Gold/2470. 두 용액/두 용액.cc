#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
pair<int, int> answer;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int a; cin >> a; arr.push_back(a);
	}
	
	sort(arr.begin(), arr.end());
	
	int st = 0; int en = n-1;
	int m = abs(arr[st] + arr[en]);
	answer = {arr[st], arr[en]};
	
	while(st < en-1){
		int a = abs(arr[st] + arr[en-1]);
		int b = abs(arr[st+1] + arr[en]);
		
		if(a < b){
			en--;
			if(a < m){
				m = a;
				answer = {arr[st], arr[en]};						
			}
		}
		else{
			st++;
			if(b < m){
				m = b;
				answer = {arr[st], arr[en]};								
			}
		}
	}
	
	cout << answer.first << ' ' << answer.second;
}

