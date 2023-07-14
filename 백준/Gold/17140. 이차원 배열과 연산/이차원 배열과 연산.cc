	#include <bits/stdc++.h>

using namespace std;

int r, c, k;
int y = 3, x = 3;
int board[201][201];
int t;
int num[101];

void R(){
	int len = x;
	for(int i=1; i<=y; i++){
		fill(num, num+101, 0);
		vector<pair<int, int>> arr;
		for(int j=1; j<=x; j++){
			num[board[i][j]]++;
			board[i][j] = 0;
		}
		for(int k=1; k<=100; k++){
			if(num[k] >= 1){
				arr.push_back({num[k], k});
			}
		}
		int l = arr.size();
		len = max(len, l*2);
		sort(arr.begin(), arr.end());
		for(int j=1; j<=arr.size(); j++){
			board[i][j*2-1] = arr[j-1].second;
			board[i][j*2] = arr[j-1].first;
		}
	}	
	if(len > 100) x = 100;
	else x = max(len, x);
}

void C(){
	int len = y;
	for(int j=1; j<=x; j++){
		fill(num, num+101, 0);
		vector<pair<int, int>> arr;
		for(int i=1; i<=y; i++){
			num[board[i][j]]++;
			board[i][j] = 0;
		}
		for(int k=1; k<=100; k++){
			if(num[k] >= 1){
				arr.push_back({num[k], k});
			}
		}
		int l = arr.size();
		len = max(len, l*2);
		sort(arr.begin(), arr.end());
		for(int i=1; i<=arr.size(); i++){
			board[i*2-1][j] = arr[i-1].second;
			board[i*2][j] = arr[i-1].first;
		}
	}	
	if(len > 100) y = 100;
	else y = max(len, y);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c >> k;	
	
	for(int i=1; i<=3; i++){
		
		for(int j=1; j<=3; j++){
			cin >> board[i][j];
		}
	}
	
	int stk = 0;
	while(stk <= 100){
		if(board[r][c] == k){
			cout << stk;
			return 0;
		}
		if(y >= x){
			R();
		}
		else C();

		stk++;
	}
	
	cout << -1;
	return 0;
}