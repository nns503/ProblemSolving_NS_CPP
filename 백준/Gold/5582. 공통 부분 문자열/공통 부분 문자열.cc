#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int lcs[4001][4001];
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s1;
	cin >> s2;	
	
	for(int i=0; i<s1.size(); i++){
		if(s1[i] == s2[0]){
			lcs[i][0] = 1;
		}
	}
	
	for(int i=0; i<s2.size(); i++){
		if(s1[0] == s2[i]){
			lcs[0][i] = 1;
		}
	}
	
	for(int i=1; i<s1.size(); i++){
		for(int j=1; j<s2.size(); j++){
			if(s1[i] == s2[j]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
				answer = max(answer, lcs[i][j]);
			}
		}
	}
	
	cout << answer;
	return 0;
}

