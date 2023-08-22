#include <bits/stdc++.h>

using namespace std;

string s, target;
string answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	cin >> target;
	
	for(char c : s){
		answer.push_back(c);
		if(answer.size() >= target.size()){
			string temp = answer.substr(answer.size() - target.size(), answer.size());
			if(temp == target){
				answer.erase(answer.size() - target.size(), answer.size());
			}
		}
	}

	cout << (answer.empty()?"FRULA":answer);
	return 0;
}