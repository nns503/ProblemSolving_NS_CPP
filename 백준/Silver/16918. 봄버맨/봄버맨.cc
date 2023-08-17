#include <bits/stdc++.h>

using namespace std;

int r, c, n;
string board[201];
int sc[201][201];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void printBoard(){
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(sc[y][x] != 0) cout << 'O';
			else cout << '.';
		}
		cout << '\n';
	}	
}

void printT(){
	cout <<"@@\n";
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			cout << sc[y][x];
		}
		cout << '\n';
	}	
	cout << '\n';
}

void setTime(){
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(sc[y][x] != 0) sc[y][x]++;
		}
	}	
}

void setBoom(){
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(sc[y][x] == 0) sc[y][x]++;
		}
	}		
}

void Boom(){
	int temp[201][201];
	
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			temp[y][x] = sc[y][x];
		}
	}	

	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(temp[y][x] == 4){
				sc[y][x] = 0;
				for(int i=0; i<4; i++){
					int ny = y + dy[i];
					int nx = x + dx[i];
					if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
					sc[ny][nx] = 0;
				}
			}
		}
	}
	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c >> n;
	
	for(int i=0; i<r; i++){
		cin >> board[i];
	}
	
	for(int y=0; y<r; y++){
		for(int x=0; x<c; x++){
			if(board[y][x] == 'O'){
				sc[y][x] = 2;
			} 
		}
	}
	
	for(int i=2; i<=n; i++){
		setTime();
		if(i % 2 == 0) setBoom();
		else Boom();
	}

	
	printBoard();
	
	return 0;
}