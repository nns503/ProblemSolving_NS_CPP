#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n, m;
int answer = 100;
int board[9][9];
vector<pair<int, int>> arr;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int getSpot(){
	int spot = 0;
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			if(board[y][x] == 0) spot++;
		}
	}
	return spot;
}

void setLeft(int cy, int cx, int state){
	if(state == 1){
		for(int x=cx-1; x>=0; x--){
			if(board[cy][x] <= 0) board[cy][x]--;
			else if(board[cy][x] == 6) break;
		}
	}
	else{
		for(int x=cx-1; x>=0; x--){
			if(board[cy][x] <= 0) board[cy][x]++;
			else if(board[cy][x] == 6) break;
		}
	} 
}

void setRight(int cy, int cx, int state){
	if(state == 1){
		for(int x=cx+1; x<m; x++){
			if(board[cy][x] <= 0) board[cy][x]--;
			else if(board[cy][x] == 6) break;
		}
	}
	else{
		for(int x=cx+1; x<m; x++){
			if(board[cy][x] <= 0) board[cy][x]++;
			else if(board[cy][x] == 6) break;
		}
	} 
}

void setUp(int cy, int cx, int state){
	if(state == 1){
		for(int y=cy-1; y>=0; y--){
			if(board[y][cx] <= 0) board[y][cx]--;
			else if(board[y][cx] == 6) break;
		}
	}
	else{
		for(int y=cy-1; y>=0; y--){
			if(board[y][cx] <= 0) board[y][cx]++;
			else if(board[y][cx] == 6) break;
		}
	} 
}

void setDown(int cy, int cx, int state){
	if(state == 1){
		for(int y=cy+1; y<n; y++){
			if(board[y][cx] <= 0) board[y][cx]--;
			else if(board[y][cx] == 6) break;
		}
	}
	else{
		for(int y=cy+1; y<n; y++){
			if(board[y][cx] <= 0) board[y][cx]++;
			else if(board[y][cx] == 6) break;
		}
	} 
}

void func(int cnt){
	if(cnt == arr.size()){
		answer = min(answer, getSpot());
		return ;
	}
	
	int cy = arr[cnt].Y; 
	int cx = arr[cnt].X;
	int num = board[cy][cx];
	if(num == 1){
		setUp(cy, cx, 1);
		func(cnt+1);
		setUp(cy, cx, 0);
		setDown(cy, cx, 1);
		func(cnt+1);
		setDown(cy, cx, 0);
		setRight(cy, cx, 1);
		func(cnt+1);
		setRight(cy, cx, 0);
		setLeft(cy, cx, 1);
		func(cnt+1);
		setLeft(cy, cx, 0);
	}
	else if(num == 2){
		setUp(cy, cx, 1);
		setDown(cy, cx, 1);
		func(cnt+1);
		setUp(cy, cx, 0);
		setDown(cy, cx, 0);
		setRight(cy, cx, 1);	
		setLeft(cy, cx, 1);
		func(cnt+1);
		setRight(cy, cx, 0);
		setLeft(cy, cx, 0);		
	}
	else if(num == 3){
		setUp(cy, cx, 1);
		setRight(cy, cx, 1);
		func(cnt+1);
		setUp(cy, cx, 0);
		setDown(cy, cx, 1);
		func(cnt+1);
		setRight(cy, cx, 0);
		setLeft(cy, cx, 1);
		func(cnt+1);
		setDown(cy, cx, 0);
		setUp(cy, cx, 1);
		func(cnt+1);
		setLeft(cy, cx, 0);
		setUp(cy, cx, 0);
	}
	else if(num == 4){
		setUp(cy, cx, 1);
		setRight(cy, cx, 1);		
		setLeft(cy, cx, 1);
		func(cnt+1);
		setLeft(cy, cx, 0);
		setDown(cy, cx, 1);
		func(cnt+1);
		setUp(cy, cx, 0);
		setLeft(cy, cx, 1);
		func(cnt+1);
		setRight(cy, cx, 0);
		setUp(cy, cx, 1);
		func(cnt+1);
		setUp(cy, cx, 0);
		setLeft(cy, cx, 0);
		setDown(cy, cx, 0);
	}
	else if(num == 5){
		setUp(cy, cx, 1);
		setDown(cy, cx, 1);
		setRight(cy, cx, 1);
		setLeft(cy, cx, 1);
		func(cnt+1);
		setUp(cy, cx, 0);
		setDown(cy, cx, 0);
		setRight(cy, cx, 0);
		setLeft(cy, cx, 0);
	}
	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++){
			cin >> board[y][x];
			if(board[y][x] >= 1 && board[y][x] <= 5){
				arr.push_back({y, x});
			}
		}
	}
	
	func(0);
	
	cout << answer;
	
	return 0;
}