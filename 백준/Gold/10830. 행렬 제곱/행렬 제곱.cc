#include <bits/stdc++.h>

using namespace std;

int n;
long long b;
vector<vector<int>> A;
vector<vector<int>> mat;

vector<vector<int>> multi(vector<vector<int>> A, vector<vector<int>> B){
	vector<vector<int>> temp;
	for(int y=0; y<n; y++){
		vector<int> arr;
		
		for(int x=0; x<n; x++){
			arr.push_back(0);
			for(int i=0; i<n; i++){
				arr[x] += (A[y][i] * B[i][x]) % 1000;
			}
			arr[x] %= 1000;
		}
		temp.push_back(arr);
	}
	
	return temp;
}

vector<vector<int>> func(vector<vector<int>> A, long long exp){
	if(exp == 1){
		return A;
	}
	if(!(exp % 2)){
		vector<vector<int>> half = func(A, exp/2);
		return multi(half, half);
	} 
	else{
		return multi(func(A,exp-1), A);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> b;
	
	for(int i=0; i<n; i++){
		vector<int> arr;
		for(int j=0; j<n; j++){
			int a; cin >> a;
			arr.push_back(a);
		}
		A.push_back(arr);
	}	
	
	mat = func(A, b);
	
	for(int i=0; i<n; i++){;
		for(int j=0; j<n; j++){
			cout << mat[i][j] % 1000 << ' ';
		}
		cout << '\n';
	}	
	
	return 0;
}