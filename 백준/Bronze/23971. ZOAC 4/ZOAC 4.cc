#include <bits/stdc++.h>

using namespace std;

int h, w, n, m;
int answer;

int main(void){
	cin >> h >> w >> n >> m;
	answer = ((h+n)/(n+1)) * ((w+m)/(m+1));
	cout << answer; 
	return 0;
}