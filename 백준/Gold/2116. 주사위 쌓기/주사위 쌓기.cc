#include <bits/stdc++.h>

using namespace std;

int t;
int dice[10001][7];
int op[6] = {5, 3, 4, 1, 2, 0};
int answer;

int func(int n, int i){
	if(dice[n][i] != 6 && dice[n][op[i]] != 6) return 6;
	else if(dice[n][i] != 5 && dice[n][op[i]] != 5) return 5;
	else return 4;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	for(int i=0; i<t; i++){
		for(int k=0; k<6; k++){
			cin >> dice[i][k];
		}
	}
	
	int prv; 
	
	for(int i=0; i<6; i++){
		int temp = 0;
		prv = dice[0][op[i]];	
		temp += func(0, i);
		for(int n=1; n<t; n++){
			for(int k=0; k<6; k++){
				if(dice[n][k] == prv){
					temp += func(n, k);
					prv = dice[n][op[k]];
					break;
				}
			}
		}
		answer = max(answer, temp);
	}
	
	cout << answer;
	return 0;
}