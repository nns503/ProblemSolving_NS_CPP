#include <bits/stdc++.h>

using namespace std;

int n, d, k, c;
int sushi[60001];
int chk[3001];;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d >> k >> c;
	for(int i=0; i<n; i++) cin >> sushi[i];
	for(int i=0; i<n; i++) sushi[n+i] = sushi[i];
	
	n *= 2;
	int answer = 0;
	int en = 0;
	int len = 0;
	for(int st=0; st<n; st++){
		while(en < n && en-st < k){
			if(chk[sushi[en]] == 0 && sushi[en] != c){
				len++;
			}
			chk[sushi[en]]++;
			en++;
		} 
		answer = max(answer, len);
		if(chk[sushi[st]] == 1 && sushi[st] != c) len--;
		chk[sushi[st]]--;	
	}
	
	cout << answer+1;
	return 0;
}