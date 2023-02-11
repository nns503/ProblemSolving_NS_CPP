	#include <iostream>
	#include <string>
	#include <vector>
	#include <algorithm>
	#include <queue>
	
	using namespace std;
	
	
	void DFS(vector<int> graph[], int color[], int start){
		if(color[start]==0) color[start] = 1;	
		
		for(int i=0;i<graph[start].size();i++){
			int next = graph[start][i];
			
			if(color[next]==0){
				if(color[start]==1) color[next]=2;
				else if(color[start]==2) color[next]=1; 
				DFS(graph,color,next);
			}
		}
	}
	
	bool isBipartitegraph(vector<int> graph[], int color[], int n){
		for(int i=1;i<=n;i++){
			for(int j=0;j<graph[i].size();j++){
				if(color[i]==color[graph[i][j]]){
					return false;
				}
			}
		}
		return true;
	}
	
	
	int main(void){
		int k; 
		cin >> k;
		
		for(int i=0;i<k;i++){
			vector<int> graph[20001];
			int color[20001];
			int n,m;
			cin >> n >> m;
			fill_n(color,n+1,0);	
			for(int j=0;j<m;j++){
				int u,v;
				cin >> u >> v;
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
			for(int j=1;j<=n;j++){
				DFS(graph,color,j);
			}
			cout << (isBipartitegraph(graph,color,n)?"YES":"NO") << "\n" ;
		}
		
		return 0;
	}
