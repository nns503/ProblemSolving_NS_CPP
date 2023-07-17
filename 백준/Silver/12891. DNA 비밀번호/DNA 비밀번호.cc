#include <bits/stdc++.h>

using namespace std;

string dna;
int a[4];
int b[4];
int s, p;
int answer;

int func(char c){
	if(c == 'A') return 0;
	else if(c == 'C') return 1;
	else if(c == 'G') return 2;
	else if(c == 'T') return 3;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> p;
	cin >> dna;
	
	for(int i=0; i<4; i++){
		cin >> b[i];
	}
	
	for(int i=0; i<s; i++){
		bool chk = true;
		a[func(dna[i])]++;
		if(i >= p){
			a[func(dna[i-p])]--;
		}
		
		for(int j=0; j<4; j++){
			if(a[j] < b[j]){
				chk = false;
				break;
			}
		}
		
		if(i >= p - 1 && chk) answer++;
	}
	
	cout << answer;
		
	return 0;
}