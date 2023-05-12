#include <bits/stdc++.h>

using namespace std;

int h, w;
int answer;
vector<int> v(501);

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	
	for(int x=1; x<=w; x++){
		cin >> v[x];
	}
	
	for(int y=1; y<=h; y++){
		int st = -1;
		int temp = 0;
		for(int x=1; x<=w; x++){
			if(st == -1 && v[x] >= y){
				st = x;
			}
			else if(st != -1 && v[x] < y){
				temp++;
			}
			else if(st != -1 && v[x] >= y){
				st = x;
				answer += temp;
				temp = 0;
			} 
		}
	}
	
	cout << answer;
	
	return 0;
}