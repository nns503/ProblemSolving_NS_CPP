#include <iostream>
#include <algorithm>
#include <cmath>	
#include <string>
#include <climits>

using namespace std;



int main(void){
	int n,m;
	int temp = 0;
	int min = 10000;
	cin >> n >> m;
	char map[51][51];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> map[i][j];
		}
	}	
	
	for(int k=1;k<=n-7;k++){
		for(int t=1;t<=m-7;t++){
			for(int i=k;i<=k+7;i++){
				for(int j=t;j<=t+7;j++){
					if((i+j)%2==0&&(map[i][j]!='B')) temp++;
					else if((i+j)%2!=0&&(map[i][j]!='W')) temp++;
				}
			}		
			if(min>temp) min=temp;
			temp = 0;
			for(int i=k;i<=k+7;i++){
				for(int j=t;j<=t+7;j++){
					if((i+j)%2==0&&(map[i][j]!='W')) temp++;
					else if((i+j)%2!=0&&(map[i][j]!='B')) temp++;
				}
			}
			if(min>temp) min=temp;	
			temp = 0;
		}
	}
	
	cout << min;
	
	return 0;
}

