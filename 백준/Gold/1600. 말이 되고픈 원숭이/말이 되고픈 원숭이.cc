#include <bits/stdc++.h>

using namespace std;

int k,w,h;
int board[201][201];
int vis[201][201][31];
int hx[8] = {1,2,2,1,-1,-2,-2,-1};
int hy[8] = {2,1,-1,-2,-2,-1,1,2};
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
queue<tuple<int,int,int>> Q;


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	cin >> w >> h;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			cin >> board[i][j];
	}
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			fill(vis[i][j],vis[i][j]+k+1,-1);
		
	vis[0][0][0] = 0;
	Q.push(make_tuple(0,0,0));
	
	while(!Q.empty()){
		int curX = get<0>(Q.front());
		int curY = get<1>(Q.front());
		int horse = get<2>(Q.front());
		Q.pop();
		if(horse<k){
			for(int i=0;i<8;i++){
				int nx = curX + hx[i];
				int ny = curY + hy[i];
				if(nx<0||ny<0||nx>=w||ny>=h) continue;
				if(vis[ny][nx][horse+1]!=-1||board[ny][nx]==1) continue;
				Q.push(make_tuple(nx,ny,horse+1));
				vis[ny][nx][horse+1]=vis[curY][curX][horse]+1;
			}
		}
		for(int i=0;i<4;i++){
			int nx = curX + mx[i];
			int ny = curY + my[i];
			if(nx<0||ny<0||nx>=w||ny>=h) continue;
			if(vis[ny][nx][horse]!=-1||board[ny][nx]==1) continue;
			Q.push(make_tuple(nx,ny,horse));
			vis[ny][nx][horse]=vis[curY][curX][horse]+1;
		}		
	}
	
	int answer = 100000;
	for(int i=0;i<=k;i++){
		if(vis[h-1][w-1][i]==-1) continue;
		answer = min(answer,vis[h-1][w-1][i]);
	}
	if(answer==100000) answer=-1;
	cout << answer;
	
	return 0;
}