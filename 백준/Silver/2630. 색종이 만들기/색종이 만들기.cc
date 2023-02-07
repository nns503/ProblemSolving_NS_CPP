#include <iostream>

using namespace std;

int map[129][129];
int blue = 0, white = 0;

void paper(int x, int y, int size){
	int color = map[y][x];
	bool same = true;
	for(int i=y;i<y+size;i++){
		for(int j=x;j<x+size;j++){
			if(color!=map[i][j]){
				same=false;
				break;
			}
		}
		if(same==false) break;
	}
	
	if(same==true){
		if(color==0) white++;
		else if(color==1) blue++;
	}
	else if(same==false){
		paper(x+size/2,y,size/2);
		paper(x,y,size/2);
		paper(x,y+size/2,size/2);
		paper(x+size/2,y+size/2,size/2);
	}
}

int main(void){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	paper(0,0,n);
	
	cout << white << "\n" << blue;
	
	return 0;
}
