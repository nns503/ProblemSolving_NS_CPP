#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#include <climits>

using namespace std;


int main(void){
	
	int min = 256;
	int max = 0;
	int time=0;
	int work;
	int result[2];
	result[0] = INT_MAX;
	result[1] = 0;
	int n,m,b;
	cin >> n >> m >> b;	
	int map[501][501];
	
	int tb = b;
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			if(map[i][j]>max) max=map[i][j];
			if(map[i][j]<min) min=map[i][j];
		}
	}
	
	while(min<=max){	
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				work = map[i][j]-min;
				if(work>0) {
					time += work*2;
					tb += work;
				}
				else if(work<0){
					time += work*-1;
					tb += work;
				}
			}
		}
		if(time<=result[0]&&tb>=0) {
			result[0] = time;
			result[1] = min;
		}  
		
		time=0;
		min++;
		tb = b;
	}
	
	cout << result[0] << " " << result[1];
	return 0;
}
 
