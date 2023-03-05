#include <bits/stdc++.h>

using namespace std;

int L, R, C;
char board[31][31][31];
int vis[31][31][31];
int dz[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dx[6] = {1, 0, -1, 0, 0, 0};

bool OOB(int z, int y, int x){
	return (z<0 || y<0 || x<0 || z>=L || y>=R || x>=C);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		queue<tuple<int, int, int>> Q;
		bool chk = true;
		cin >> L >> R >> C;
		if(L==0 && R==0 && C==0) break;
		for(int z=0; z<L; z++)
			for(int y=0; y<R; y++)
				for(int x=0; x<C; x++)
					cin >> board[z][y][x];
					
		for(int z=0; z<L; z++)
			for(int y=0; y<R; y++)
				for(int x=0; x<C; x++){
					vis[z][y][x] = -1;
					if(board[z][y][x]=='S'){
						Q.push(make_tuple(z, y, x));
						vis[z][y][x] = 0;
					}
				}
					
		while(!Q.empty()){
			if(!chk) break;
			tuple<int, int, int> cur = Q.front();
			Q.pop();
			for(int i=0; i<6; i++){
				int nz = get<0>(cur) + dz[i];
				int ny = get<1>(cur) + dy[i];
				int nx = get<2>(cur) + dx[i];
				if(OOB(nz, ny, nx)) continue;
				if(board[nz][ny][nx]=='E'){
					cout << "Escaped in " << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1 << " minute(s).\n";
					chk = false; 
					break;
				}
				if(board[nz][ny][nx]!='.'||vis[nz][ny][nx]!=-1) continue;
				Q.push(make_tuple(nz, ny, nx));
				vis[nz][ny][nx] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
			}
		}
		if(chk) cout << "Trapped!\n";
	}
	
	return 0;
}