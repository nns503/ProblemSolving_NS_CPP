#include <bits/stdc++.h>

using namespace std;

int n[3];
int answer;

bool chk(){
	sort(n, n+3);
	return(n[0] + 1 == n[1] && n[1] + 1 == n[2]);
}


int main(void){
	cin >> n[0] >> n[1] >> n[2];
	
	while(!chk()){
		if(n[1] - n[0] > n[2] - n[1]){
			n[2] = n[1] - 1;
		}
		else n[0] = n[1] + 1;
		answer++;
	}
	
	cout << answer;
	return 0;
}