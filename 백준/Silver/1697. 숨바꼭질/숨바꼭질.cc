#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cp[200005];
int check[200005];

int BFS(int n, int k){
	queue<int> q;
	bool out = false;
	int number = 0;
	check[n] = 1;
	q.push(n);	
	int max = (n>k)?n:k;
	if(n==k) return 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		number = check[x];
		for(int i=0;i<=2;i++){
			int z;
			if(i==0) z=x-1;
			else if(i==1) z=x+1;
			else if(i==2) z=x*2; 
			if(z==k){
				while(!q.empty()) q.pop();
				break;
			}
			
			if(check[z]==0&&z>=0&&z<=100001){
				q.push(z);
				check[z] = check[x]+1;
			}
		}
	}
	return (number);
}


int main(void){
	int n,k;
	cin >> n >> k;
	fill_n(check,200005,0);
	
	cout << BFS(n,k);
	return 0;
}