#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	queue<int> q;
	int turn=1;
	
	cin >> n >> k;
	
	for(int i = 1; i<=n; i++){
		q.push(i);
	}
	
	cout << '<';
	while(q.size()!=1){
		if(turn==k){
			turn = 1;
			cout << q.front() << ", ";
			q.pop();
		}
		else{  //turn!=k
			turn++;
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}
	cout << q.front() << '>';
	
	return 0;
}