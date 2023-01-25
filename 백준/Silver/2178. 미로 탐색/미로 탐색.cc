	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <queue>
	using namespace std;
	
	int w,h;
	int min = 15000;
	string input[101];
	int map[101][101];
	bool check[101][101];
	int dist[101][101];
	int dw[4]= {1,0,-1,0};
	int dh[4]= {0,1,0,-1};
	queue<pair<int,int>> q;
	
	
	void BFS(int y, int x){
		
		check[y][x] = true;
		q.push(make_pair(y,x));
		dist[y][x] = 1;	
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int nh = p.first + dh[i];
				int nw = p.second + dw[i];
				if(nw>=1&&nh>=1&&nw<=w&&nh<=h&&!check[nh][nw]&&map[nw][nh]==1){
					q.push(make_pair(nh,nw));
					check[nh][nw] = true;
					dist[nh][nw]=dist[p.first][p.second]+1;
				}
			}
		}
	}

	
	int main(void){

		cin >> w >> h;
		
		for(int j=1;j<=w;j++){
			cin >> input[j];
		}
		
		for(int i=1;i<=w;i++){
			for(int j=1	;j<=h;j++){
				map[i][j] = input[i][j-1]-'0';
			}
		}
		
				
		fill(&check[0][0],&check[101][101],false);
		BFS(1,1);
		cout << dist[h][w];
	
		
		return 0;
}
	
