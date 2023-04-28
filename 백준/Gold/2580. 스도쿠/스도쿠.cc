#include <bits/stdc++.h>

using namespace std;

int board[82];
bool h[10][10];
bool w[10][10];
bool box[4][4][10];
int cnt;
bool chk;

void func(int index){
	if(cnt == 81){
		chk = true;
		return;
	}
	for(int i=index; i<81; i++){
		if(board[i] != 0) continue;
		for(int n=1; n<=9; n++){
			int ny = i / 9;
			int nx = i % 9;
			if(h[ny][n]) continue;
			if(w[nx][n]) continue;
			if(box[ny/3][nx/3][n]) continue;
			h[ny][n] = true; w[nx][n] = true; box[ny/3][nx/3][n] = true;
			board[i] = n;
			cnt++;
			func(i+1);
			if(chk) return;
			board[i] = 0;
			cnt--;
			h[ny][n] = false; w[nx][n] = false; box[ny/3][nx/3][n] = false;
		}
		return;
	} 
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			int n;
			cin >> n;
			board[9*i + j] = n;
			if(n != 0){
				h[i][n] = true;
				w[j][n] = true;
				box[i/3][j/3][n] = true;
				cnt++;
			}
		}
	}
	
	func(0);
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout << board[9*i + j] << ' ';
		}
		cout << '\n';
	}	
	
	return 0;
}