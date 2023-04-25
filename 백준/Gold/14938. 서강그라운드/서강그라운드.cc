#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int board[101][101];
int t[101];
int getItem[101];
int n, m , r;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> r;
	for(int i=1; i<=n; i++) cin >> t[i];
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j) board[i][j] = 0;
			else{
				board[i][j] = 1000000;
			}
		}
	}

	for(int i=0; i<r; i++){
		int a, b, l;
		cin >> a >> b >> l;
		board[a][b] = l;
		board[b][a] = l;
	}
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				board[i][j] = min(board[i][k] + board[k][j], board[i][j]);
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(board[i][j] <= m){
				getItem[i] += t[j];
			}
		}
	}

	cout << *max_element(getItem, getItem+n+1);
	return 0;
}