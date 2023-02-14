#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	deque<int> dq;
	int n,m;
	int move = 0;
	
	cin >> n >> m;	
	for(int i=1;i<=n;i++){
		dq.push_back(i);
	}
	
	while(m--){
		int f;
		cin >> f;
		int index = find(dq.begin(),dq.end(),f)-dq.begin();
		while(dq.front()!=f){
			move++;
			if(index<dq.size()-index){
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else{   // index >= dq.size()-index
				 dq.push_front(dq.back());
				 dq.pop_back();
			}
		}
		dq.pop_front();
	}
	cout << move;
	return 0;
}

