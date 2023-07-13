#include <bits/stdc++.h>

using namespace std;

int n, answer;
vector<string> dr;
vector<pair<int, char>> arr;
int alp[27];
int num[27];

bool cmp(pair<int, char> a, pair<int, char> b){
	return a.first > b.first;	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for(int i=0; i<n; i++){
		string s; cin >> s; dr.push_back(s);
		for(int j=0; j<s.size(); j++){
			alp[s[j] - 'A'] += pow(10, s.size() - j);
		}
	}	
	
	for(int i=0; i<=26; i++){
		if(alp[i] > 0){
			arr.push_back({alp[i], i + 'A'});
		} 
	}
	
	sort(arr.begin(), arr.end(), cmp);
	
	int cnt = 9;
	for(int i=0; i<arr.size(); i++){
		num[arr[i].second - 'A'] = cnt;
		cnt--; 
	}
	
	for(int i=0; i<dr.size(); i++){

		int temp = 0;
		for(int j=0; j<dr[i].size(); j++){
			temp *= 10;
			temp += num[dr[i][j] - 'A'];
		}
		answer += temp;
	}
	
	
	cout << answer;
	
	return 0;

}