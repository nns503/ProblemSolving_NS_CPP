#include <bits/stdc++.h>
#define a first
#define b second


using namespace std;

int n;
stack<pair<int, int>> s;
int h, num;
vector<int> arr;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	s.push({0, 0x3f3f3f3f});
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> h;
		arr.push_back(h);
	}
	
	while(n > num){
		
		while(s.top().b < arr[num]){
			s.pop();
		}
		
		cout << s.top().a << ' ';
		s.push({num+1, arr[num]});
		num++;
		
	}
	
	return 0;
}