#include <bits/stdc++.h>

using namespace std;

int r, c, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
vector<tuple<int, int, int>> sk;
int board[101][101]; 
int temp[101][101];
int result;

void moveShark(){
	for(int i=0; i<101; i++) fill(temp[i], temp[i]+101, -1);
	
	for(int y=1; y<=r; y++){
		for(int x=1; x<=c; x++){
			if(board[y][x] != -1){
				int cnt = get<0>(sk[board[y][x]]);
				int ny = y;
				int nx = x;
				while(cnt--){
				int dir = get<1>(sk[board[y][x]]);					
					if(dir == 0 || dir == 1){
						if(ny == r) get<1>(sk[board[y][x]]) = 0;
						else if(ny == 1) get<1>(sk[board[y][x]]) = 1;
						ny += dy[get<1>(sk[board[y][x]])];
					}
					else{
						if(nx == c) get<1>(sk[board[y][x]]) = 3;
						else if(nx == 1) get<1>(sk[board[y][x]]) = 2;	
						nx += dx[get<1>(sk[board[y][x]])];					
					}
				}
				if(temp[ny][nx] == -1) temp[ny][nx] = board[y][x];
				else{
					if(get<2>(sk[temp[ny][nx]]) < get<2>(sk[board[y][x]])){
						temp[ny][nx] = board[y][x];
					}
				}
			}
		}
	}

	for(int y=1; y<=r; y++){
		for(int x=1; x<=c; x++){
			board[y][x] = temp[y][x];
		}
	}
}

void getShark(int x){
	for(int y=1; y<=r; y++){
		if(board[y][x] != -1){
			result += get<2>(sk[board[y][x]]);
			board[y][x] = -1;
			return ;
		}
	}

}

int main(void){
	
	cin>> r >> c >> m;
	
	for(int i=0; i<101; i++) fill(board[i], board[i]+101, -1);
	
	for(int i=0; i<m; i++){
		int a, b, s, d, z;
		cin >> a >> b >> s >> d >> z;
		board[a][b] = i;
		sk.push_back(make_tuple(s, d-1, z));
	}
	for(int x = 1; x<=c; x++){
		getShark(x);
		moveShark();
	}
	cout << result;
	return 0;
}