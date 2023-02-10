#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v(101,0);
vector<int> check(101,0);

int BFS() {
	queue<int> q;
	check[1] = 0;
	q.push(1);
	do {
		int cur = q.front();
		q.pop();
		if (cur == 100) return check[100];
		for (int i = 1; i <= 6; i++) {
			if (cur + i > 100) break;
			if (check[cur + i] == 0 && v[cur + i] == 0) {
				q.push(cur + i);
				check[cur + i] = check[cur]+1;
			}
			else if (v[cur + i] != 0 && check[v[cur + i]] == 0 ) {
				q.push(v[cur + i]);
				check[v[cur + i]] = check[cur]+1;
			}
		}
	} while (!q.empty());
}
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		int a, b;
		cin >> a >> b;
		v[a] = b;
	}
	cout << BFS();
	return 0;
}