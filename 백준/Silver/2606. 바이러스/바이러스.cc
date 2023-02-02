#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cp[101];
bool check[101];

int DFS(){
	stack<int> s;
	int number = 0;
	check[1] = true;
	s.push(1);
	while(!s.empty()){
		int x = s.top();
		s.pop();
		for(int i=0;i<cp[x].size();i++){
			int q = cp[x][i];
			if(check[q]==false){
				s.push(q);
				number++;
				check[q] = true;
			}
		}
	}
	return number;
}


int main(void){
	int n,t;
	cin >> n >> t;
	fill_n(check,n+1,false);
	for(int i=0;i<t;i++){
		int a,b;
		cin >> a >> b;
		cp[a].push_back(b);
		cp[b].push_back(a);
	}
	
	cout << DFS();
	return 0;
}