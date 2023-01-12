#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];

void DFS(int start, bool check[]) {
	check[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		if (!check[graph[start][i]]) {
			DFS(graph[start][i], check);
		}
	}
}

int main(void) {
	int n, m;
	int link = 0;
	cin >> n >> m;
	bool check[1001];
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	fill_n(check, 1001, false);

	for (int i = 1; i <= n; i++) {
		if (check[i] == true) continue;
		else {
			DFS(i, check);
			link++;
		}
	}

	cout << link;

	return 0;
}