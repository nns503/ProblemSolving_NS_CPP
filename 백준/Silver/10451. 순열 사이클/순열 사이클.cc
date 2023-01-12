	#include <iostream>
	#include <string>
	#include <vector>
	#include <algorithm>
	#include <queue>
	
	using namespace std;
	
	
	void DFS(vector<int> graph[], bool check[], int start){
		check[start] = true;	
		
		for(int i=0;i<graph[start].size();i++){
			int next = graph[start][i];
			if(!check[next]){
				DFS(graph,check,next);
			}
		}
	}
	int main(void){
		int k;
		cin >> k;
		for(int t=0;t<k;t++){
			int n;
			cin >> n;
			int cycle = 0;
			vector<int> graph[n+1];
			bool check[n+1];
			fill_n(check,n+1,false);
			for(int i=1;i<=n;i++){
				int u;
				cin >> u;
				graph[i].push_back(u);
				graph[u].push_back(i);
			}
			
			for(int i=1;i<=n;i++){
				if(check[i]==true) continue;
				else{
					cycle++;
					DFS(graph,check,i);
				}
			}  
			
			cout << cycle << "\n";
		} 	
		
		return 0;
	}
