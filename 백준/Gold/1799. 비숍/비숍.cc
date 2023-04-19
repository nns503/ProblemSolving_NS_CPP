#include <bits/stdc++.h>

using namespace std;

int n;
int board[150];
vector<int> v[25];
bool arr1[25];
int answer;

void func(int p, int cnt){
	for(int i=p; i<2*n-1; i++){
		if(2*n-1-p+cnt <= answer) return;
		for(int j=0; j<v[i].size(); j++){
			int cur = v[i][j];
			if(board[cur] == 0) continue;
			if(arr1[cur/n - cur%n + n]) continue;
			arr1[cur/n - cur%n + n] = true;
			func(i+1, cnt+1);
			arr1[cur/n - cur%n + n] = false;
		}
	}
	answer = max(cnt, answer);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n*n; i++){
		cin >> board[i];
	}
	
	for(int y=0; y<n; y++){
		for(int x=0; x<n; x++){
			v[y+x].push_back(y*n + x);
		}
	}
	
	func(0, 0);
	cout << answer;
	return 0;
}