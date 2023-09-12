#include <bits/stdc++.h>

using namespace std;

string board[10];
string ans[10];
bool squ[10][10];
bool row[10][10];
bool col[10][10];
bool ed;

void func(int n){
	int y = n / 9;
	int x = n % 9;
	
	if(!ed && n == 81){
		for(int i=0; i<9; i++){
			ans[i] = board[i];
		}
		ed = true;
		return;		
	}
	if(board[y][x] != '0'){
		func(n+1);
		return;
	}
	
	for(int i=1; i<=9; i++){
		if(ed) break;
		if(!squ[(y / 3) * 3 + x / 3][i] && !row[x][i] && !col[y][i]){
			squ[(y / 3) * 3 + x / 3][i] = true;
			row[x][i] = true;
			col[y][i] = true;
			board[y][x] = i +'0';
			
			func(n + 1);
			
			squ[(y / 3) * 3 + x / 3][i] = false;
			row[x][i] = false;
			col[y][i] = false;
			board[y][x] = '0';
		}
	}
}

void setBool(){
	for(int i=0; i<81; i++){
		int y = i / 9;
		int x = i % 9;
		if(board[y][x] != '0'){
			squ[(y / 3) * 3 + x / 3][board[y][x] - '0'] = true;
			row[x][board[y][x] - '0'] = true;
			col[y][board[y][x] - '0'] = true; 
		}
	}	
}
int main(void){
	for(int i=0; i<9; i++){
		cin >> board[i];
	}
	
	setBool();
	func(0);
	
	for(int i=0; i<9; i++){
		cout << ans[i] << '\n';
	}
}