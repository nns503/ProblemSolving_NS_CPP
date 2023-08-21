#include <bits/stdc++.h>

using namespace std;

int n, m, r;

int arr[301][301];
int temp[301][301];

void printArr(){
	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			cout << arr[y][x] << ' ';
		}
		cout << '\n';
	}	
}
void ArrToTemp(){
	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			temp[y][x] = arr[y][x];
		}
	}
}

void moveArr(){
	ArrToTemp();	
	
	int d = 0;
	for(int y=1; y<=n/2; y++){	
		for(int x=d+1; x<=m-1-d; x++){
			arr[y][x] = temp[y][x+1];
		}
		d++;
	}
	
	d = 0;
	for(int y=n; y>(n+1)/2; y--){
		for(int x=m-d; x>=d+2; x--){
			arr[y][x] = temp[y][x-1];
		}
		d++;
	}

	d = 0;
	for(int x=1; x<=m/2; x++){

		for(int y=n-d; y>=d+2; y--){
			arr[y][x] = temp[y-1][x];
		}
		d++;
	}	
	
	d = 0;
	for(int x=m; x>(m+1)/2; x--){
		for(int y=d+1; y<=n-1-d; y++){
			arr[y][x] = temp[y+1][x];
		}
		d++;
	}
	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> r;
	
	for(int y=1; y<=n; y++){
		for(int x=1; x<=m; x++){
			cin >> arr[y][x];
		}
	}
	
	while(r--){
		moveArr();
	}
	printArr();
}