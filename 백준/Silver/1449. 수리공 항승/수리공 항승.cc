#include <bits/stdc++.h>

using namespace std;

int n, l;
int pos;
int answer;
vector<int> arr;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> l;
	while(n--){
		int a;
		cin >> a;
		arr.push_back(a);
	}
	
	sort(arr.begin(), arr.end());
	
	answer = 1;
	pos = arr[0];
	for(int i=1; i<arr.size(); i++){
		if(arr[i] - pos < l) continue;
		else{
			pos = arr[i];
			answer++;
		}
	}
	
	cout << answer;
	return 0;
}