#include <bits/stdc++.h>

using namespace std;

int answer;

vector<int> arr;
int main(void){
	int t = 10;
	while(t--){
		int a;
		cin >> a;
		arr.push_back(a);
	}
	for(int a : arr){
		if(answer + a >= 100){
			if(answer + a - 100 <= 100 - answer){
				answer += a;
			}
			break;
		}
		answer += a;
	}		
	cout << answer;
	return 0;
}