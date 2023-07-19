#include <bits/stdc++.h>
#define ll long long 
using namespace std;

long long n;
long long answer;
vector<vector<ll>> mt(2,vector<ll>(2));
const int MOD = 1000000007;

vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B){
	vector<vector<ll>> temp;
	
	for(int y=0; y<2; y++){
		vector<ll> arr;
		for(int x=0; x<2; x++){
			arr.push_back(0);
			for(int i=0; i<2; i++){
				arr[x] += A[y][i] * B[i][x] % MOD;
			}
			arr[x] %= MOD;			
		}
		temp.push_back(arr);
	}
	
	return temp;	
}

vector<vector<ll>> func(vector<vector<ll>> A, ll e){
	if(e == 1){
		return A;
	}
	else if(e % 2 == 0){
		vector<vector<ll>> half = func(A, e/2);
		return mul(half, half);
	}
	else{
		return mul(func(A, e-1), A);
	}
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	mt[0][0] = 1; mt[0][1] = 1; 
	mt[1][0] = 1; mt[1][1] = 0;  
	
	vector<vector<ll>> mat = func(mt, n);
	
	cout << mat[0][1];
	return 0;
}