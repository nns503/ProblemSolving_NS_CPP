#include <bits/stdc++.h>

using namespace std;

int neg, zero, pos;
int board[2500][2500];

bool check(int x,int y, int size){
	for(int i=x;i<x+size;i++){
		for(int j=y;j<y+size;j++){
			if(board[x][y]!=board[i][j]) return false; 
		}
	}	
	return true;
}

void solution(int x, int y, int size){	
	if(check(x,y,size)){
		if(board[x][y]==1) pos++;
		else if(board[x][y]==-1) neg++;
		else zero++;		
	}
	else{
		solution(x, y, size/3);
		solution(x+size/3, y, size/3);
		solution(x+size/3*2, y, size/3);
		solution(x, y+size/3, size/3);
		solution(x, y+size/3*2, size/3);
		solution(x+size/3, y+size/3, size/3);
		solution(x+size/3*2, y+size/3, size/3);
		solution(x+size/3, y+size/3*2, size/3);
		solution(x+size/3*2, y+size/3*2, size/3);
	}
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) cin >> board[i][j];
	}
	
	solution(0,0,N);
	cout << neg << '\n' << zero << '\n' << pos;
	
	return 0;
}

