#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		if(a==0){
			if(pq.empty()) cout << 0 << "\n";
			else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(a);
	}
	return 0;
}