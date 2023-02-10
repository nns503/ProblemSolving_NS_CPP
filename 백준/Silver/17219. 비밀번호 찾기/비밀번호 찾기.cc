#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> site;
string password[100001];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s, p;
		cin >> s >> p;
		site[s] = p;
	}
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		cout << site[s] << "\n";
	}
	return 0;
}