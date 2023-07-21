#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m, k;
int answer;
string board[1010];
int len[1010][1010];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	k = min(n, m);
	
	for(int i=0; i<n; i++){
		cin >> board[i];
	}
		
	for(int i=0; i<n; i++){
		if(board[i][0] == '1') len[i][0] = 1;
	}
	for(int i=0; i<m; i++){
		if(board[0][i] == '1') len[0][i] = 1;
	}
	
	for(int t=1; t<k; t++){
		for(int y=1; y<n; y++){
			if(board[y][t] == '1'){
				if(len[y-1][t-1] >= 1 && len[y-1][t] >= 1 && len[y][t-1] >= 1){
					len[y][t] = min(len[y-1][t-1], len[y][t-1]);
					len[y][t] = min(len[y][t], len[y-1][t]);
					len[y][t]++;								
				}
				else len[y][t] = 1;
			}
		}
		
		for(int x=1	; x<m; x++){
			if(board[t][x] == '1'){
				if(len[t-1][x-1] >= 1 && len[t-1][x] >= 1 && len[t][x-1] >= 1){
					len[t][x] = min(len[t-1][x-1], len[t][x-1]);
					len[t][x] = min(len[t][x], len[t-1][x]);
					len[t][x]++;								
				}
				else len[t][x] =1;
			}
		}
	}
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			answer = max(answer, len[y][x]);
		}
	}
	
	cout << answer*answer;

	return 0;
}