#include <bits/stdc++.h>

using namespace std;

int n, t;
string s;
vector<string> arr;
map<string, int> m;
int id = 0;
bool car[1001];
int answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> s;
		m[s] = i;
	}
	
	for(int i=0; i<n; i++){
		cin >> s;
		car[m[s]] = true;
		if(m[s] != id) answer++;
		else{
			while(car[id]){
				id++;
			}
		}
	}
	cout << answer;		
}