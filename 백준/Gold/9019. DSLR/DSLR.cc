#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int getD(int n) {
	if (n*2 > 9999) return n*2 % 10000;
	else return n*2;
}
int getS(int n) {
	if (n== 0) return 9999;
	else return n-1;
}
int getL(int n) {
	int number = n % 1000 * 10 + n / 1000;
	return number;
}
int getR(int n) {
    int number = n / 10 + n % 10 * 1000;
    return number;
}

string BFS(int start, int target) {
	vector<string> regis(10000,"");
	vector<bool> check(10000,false);
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int top = q.front();
		if (top == target) return regis[target];
		q.pop();
		int d = getD(top);
		int s = getS(top);
		int l = getL(top);
		int r = getR(top);
		if (check[d] == false) {
			q.push(d);
			check[d] = true;
			regis[d] = regis[top] + "D";
		}
		if (check[s] == false) {
			q.push(s);
			check[s] = true;
			regis[s] = regis[top] + "S";
		}
		if (check[l] == false) {
			q.push(l);
			check[l] = true;
			regis[l] = regis[top] + "L";
		}
		if (check[r] == false) {
			q.push(r);
			check[r] = true;
			regis[r] = regis[top] + "R";
		}
	}
    return 0;
}

int main(void) {
	int t, a, b;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << BFS(a, b) << "\n";
	}
	return 0;
}
