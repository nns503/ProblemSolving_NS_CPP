#include <bits/stdc++.h>

using namespace std;

int T;
double nx, mx, ny, my, r, n, cx, cy;
bool chk1, chk2;
int answer;

int getLen(double ax, double ay, double bx, double by){
	return sqrt(pow(ax-bx, 2) + pow(ay-by, 2));
} 
 
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		answer = 0;
		cin >> nx >> ny >> mx >> my;
		cin >> n;
		while(n--){
			cin >> cx >> cy >> r;
			chk2 = (r <= getLen(cx, cy, mx, my));
			chk1 = (r <= getLen(cx, cy, nx, ny));
			
			if(chk1 == chk2) continue;
			else answer++;
		}
		cout << answer << '\n';
	}

	return 0;
}
