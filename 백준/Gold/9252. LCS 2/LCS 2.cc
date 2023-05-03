#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int lcs[1001][1001];
int answer;
string result;

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
	
	int id1 = s1.size();
	int id2 = s2.size();
	
	while(id1 != 0 && id2 != 0){
		if(lcs[id1][id2] == lcs[id1-1][id2]){
			id1--;
		}
		else if(lcs[id1][id2] == lcs[id1][id2-1]){
			id2--;
		}
		else{
			result.push_back(s2[id2-1]);
			id1--; id2--;
		}
	}
	
	reverse(result.begin(), result.end());
	cout << lcs[s1.size()][s2.size()] << '\n' << result;
	return 0;
}
