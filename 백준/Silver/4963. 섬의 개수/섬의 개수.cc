	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;
	
	int w,h;
	int map[51][51];
	bool check[51][51];
	int check_w[8]= {1,0,-1,0,1,1,-1,-1};
	int check_h[8]= {0,1,0,-1,-1,1,-1,1};
	
	void DFS(int hh, int ww){
		check[hh][ww] = true;
		for(int i=0;i<8;i++){
			int nh = hh + check_h[i];
			int nw = ww + check_w[i];
			if(0<=nw&&0<=nh&&nw<w&&nh<h){
				if(map[nh][nw]==1&&!check[nh][nw]){
					DFS(nh,nw);
				}
			}
		}
	}

	
	int main(void){
		while(true){
			int number = 0;
			cin >> w >> h;
			if(w==0&&h==0) return 0;
			
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					check[i][j]=false;
				}
			}
						
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					cin >> map[i][j];
				}
			}
						
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					if(!check[i][j]&&map[i][j]==1){
						DFS(i,j);
						number++;
					}
				}
			}	
			cout << number << "\n";		
		}
	}
