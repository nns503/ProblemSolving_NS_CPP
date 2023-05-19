#include <bits/stdc++.h>

using namespace std;

string s1, target;

int main(void){
	getline(cin, s1);
	getline(cin, target);
	
	int i = 0;
	int answer = 0;
	while(s1.find(target, i) != -1){
		answer++;
		i = s1.find(target, i) + target.size();
	}	
	cout << answer;
	return 0;
}