#include <bits/stdc++.h>

using namespace std;

int m, n;
map<int, string> dr;
vector<pair<string, int>> arr;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	dr[0] = "zero";
	dr[1] = "one";
	dr[2] = "two";
	dr[3] = "three";
	dr[4] = "four";
	dr[5] = "five";
	dr[6] = "six";
	dr[7] = "seven";
	dr[8] = "eight";
	dr[9] = "nine";
	
	for(int i=10; i<=99; i++){
		int l = i % 10;
		int f = i / 10;
		dr[i] = dr[f] + dr[l];
	}
	
	cin >> n >> m;
	
	for(int i=n; i<=m; i++){
		arr.push_back({dr[i], i});
	}
	
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<arr.size(); i++){
		if(i % 10 == 0 && i > 0) cout << '\n'; 
		cout << arr[i].second << ' ';
	}
	return 0;
}