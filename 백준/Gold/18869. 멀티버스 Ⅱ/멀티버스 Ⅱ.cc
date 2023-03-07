#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int sp[101][10001];
int n, m;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> sp[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		vector<int> v;
		v.push_back(sp[i][0]);
		for(int j=1; j<m; j++){
			if(sp[i][j] != sp[i][j-1]) v.push_back(sp[i][j]);	
		}
		sort(v.begin(), v.end());
		for(int j=0; j<m; j++){
			sp[i][j] = lower_bound(v.begin(), v.end(), sp[i][j]) - v.begin();
		}	
	}
	
	int answer = 0;
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(equal(sp[i], sp[i]+m, sp[j])) answer++;
		}
	}
	
	cout << answer;
	return 0;
}