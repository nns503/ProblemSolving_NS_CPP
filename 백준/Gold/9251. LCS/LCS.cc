#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int lcs[1001][1001];
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s1 >> s2;
	
	for(int i=0; i<s1.size(); i++){
		for(int j=0; j<s2.size(); j++){
			if(s1[i] == s2[j]){
				lcs[i+1][j+1] = lcs[i][j] + 1;
			} 
			else{
				lcs[i+1][j+1] = max(lcs[i+1][j], lcs[i][j+1]);
			}
		}
	}
	cout << *max_element(lcs[s1.size()], lcs[s1.size()]+s2.size()+1);
	return 0;
}
