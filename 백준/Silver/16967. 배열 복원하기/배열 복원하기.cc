#include <bits/stdc++.h>

using namespace std;

int h, w, x, y;
int A[301][301];
int B[601][601];

int main(void){
	cin >> h >> w >> x >> y;
	
	for(int i=1; i<=h+x; i++){
		for(int j=1; j<=w+y; j++){
			cin >> B[i][j];
		}
	}
	
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(i<=x || j <=y){
				A[i][j] = B[i][j];
			}
			else{
				A[i][j] = B[i][j] - A[i-x][j-y];
			}
		}
	}
	
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}