	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <queue>
	using namespace std;
	
	int apart[350];
	int map[26][26];
	bool check[26][26];
	int dw[4]= {1,0,-1,0};
	int dh[4]= {0,1,0,-1};
	
	
	void DFS(int y, int x, int number){
		check[y][x] = true;
		apart[number]++;
		for(int i=0;i<4;i++){
			int hy = y + dh[i];
			int wx = x + dw[i];
			if((hy<0||wx<0||hy>25||wx>25)) continue;
			else if(map[hy][wx]==1&&check[hy][wx]==false){
				DFS(hy,wx,number);
			}
		}

	}

	
	int main(void){
		int number = 0;
		int n;
		cin >> n;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				char a;
				cin >> a;
				map[i][j] = a-'0';
			}
		}
		
		fill_n(apart,350,0);
		fill(&check[0][0],&check[25][25],false);	
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]==1&&!check[i][j]){
					DFS(i,j,number);
					number++;
				}
			}
		}
		
		cout << number << "\n";
		sort(apart,apart+number);
		for(int i=0;i<number;i++){
			cout << apart[i] << "\n";
		}
		
		return 0;
}
	
