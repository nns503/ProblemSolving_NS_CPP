#include <bits/stdc++.h>

using namespace std;

char board[3000][3000];
int n;

void star(int x, int y, int size){
	for(int i=x+size/3;i<x+size/3*2;i++){
		for(int j=y+size/3;j<y+size/3*2;j++){
			board[i][j] = ' ';
		}
	}
	if(size>=9){
		star(x,y,size/3);
		star(x+size/3,y,size/3);
		star(x+size/3*2,y,size/3);
		star(x,y+size/3,size/3);
		star(x,y+size/3*2,size/3);
		star(x+size/3,y+size/3,size/3);
		star(x+size/3*2,y+size/3,size/3);
		star(x+size/3,y+size/3*2,size/3);
		star(x+size/3*2,y+size/3*2,size/3);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) fill(board[i],board[i]+n,'*');
	star(0,0,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << board[i][j];
		}
		cout << '\n';
	}
	
	
}