#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>	

using namespace std;

int main(void){
	using namespace std;
	
	int n;
	cin >> n;
	char map[n][n];
	int cons=0;
	int col=0, row=0; // 행, 열
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	} 
	// 행 검사 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='.'){
				cons++;
				if(cons==2){
					col++;
				}				
			}
			else{
				cons=0;
			}
		}
		cons=0;
	}

	// 열 검사 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[j][i]=='.'){
				cons++;
				if(cons==2){
					row++;
				}
			}
			else{
				cons=0;
			}
		}
		cons=0;
	}
	
	cout << col << " " << row; 	
	return 0;
}
