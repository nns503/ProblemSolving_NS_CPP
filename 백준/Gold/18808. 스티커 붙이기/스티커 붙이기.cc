#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int sy, sx;
int n,m;
int k;
bool board[45][45];
bool tb[45][45];
bool stk[12][12];

void copyBoard(){
	for(int i=0;i<n;i++)
		copy(board[i],board[i]+m,tb[i]);
}
bool isRangeout(int y, int x){
	return (x<0||y<0||x+sx>m||y+sy>n);
}

void setRotate(){
	int R = sy;
	int C = sx;
	int temp[12][12];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			temp[j][R-1-i] = stk[i][j];
		}
	}
	for(int i=0;i<C;i++)
		for(int j=0;j<R;j++)
			stk[i][j] = temp[i][j];
	
	int t = sx;
	sx = sy;
	sy = t;
} 

bool setBoard(){
	for(int y=0;y<n;y++){
		for(int x=0;x<m;x++){
			if(isRangeout(y,x)) continue;
			copyBoard();
			bool bk = true;
			for(int i=0;i<sy;i++){
				for(int j=0;j<sx;j++){
					if(stk[i][j]){
						if(tb[y+i][x+j]) {
							bk = false;
							break;
						}
						tb[y+i][x+j]=true;
					}
				}
				if(!bk) break;
			}
			if(bk){
				for(int q=0;q<n;q++)
					copy(tb[q],tb[q]+m,board[q]);
				return true;			
			}
		}
	}
	return false;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	while(k--){
		cin >> sy >> sx;
		for(int a=0;a<sy;a++)
			for(int b=0;b<sx;b++) cin >> stk[a][b];
		
		for(int a=0;a<4;a++){
			if(setBoard()==true){
				break;
			}
			else setRotate();
		}				
	}
	int answer = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(board[i][j]==true) answer++;
		}
	cout << answer;	
	
	return 0;
}