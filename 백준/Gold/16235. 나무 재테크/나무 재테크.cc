#include <bits/stdc++.h>

using namespace std;

int n, m, k; // n = 땅의 크기, m = 구매한 나무 수, k = 마지막 년도 
int nut[11][11];
int A[11][11]; // S2D2 
deque<tuple<int, int, int>> tr;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i=1; i<=n; i++) fill(nut[i], nut[i]+n+1, 5); // 초기 S2D2  값
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> A[j][i];
		}
	} 
	
	vector<tuple<int, int, int>> temp;
	
	for(int i=0; i<m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		temp.push_back(make_tuple(z, x, y));
	}
	
	sort(temp.begin(), temp.end());
	
	for(int i=0; i<temp.size(); i++){
		tr.push_back(temp[i]);

	}
	while(k--){
		deque<tuple<int, int, int>> d;
		// Spring + Summer
		int len = tr.size();
		for(int i=0; i<len; i++){
			tuple<int, int, int> cur = tr.front();
			tr.pop_front();
			int z = get<0>(cur);
			int x = get<1>(cur);
			int y = get<2>(cur);
			if(nut[y][x] >= z){
				tr.push_back(make_tuple(z+1, x, y));
				nut[y][x] -= z;
			}
			else{
				d.push_back(make_tuple(z, x, y));
			}
		}	
		
		while(!d.empty()){
			tuple<int, int, int> cur = d.front();
			d.pop_front();
			int z = get<0>(cur);
			int x = get<1>(cur);
			int y = get<2>(cur);	
			nut[y][x] += z/2;		
		}
		
		// Fall
		len = tr.size();
		deque<tuple<int, int, int>> t;
		for(int i=0; i<len; i++){
			tuple<int, int, int> cur = tr.front();
			tr.pop_front();
			tr.push_back(cur);
			int z = get<0>(cur);
			int x = get<1>(cur);
			int y = get<2>(cur);
			if(z % 5 == 0){
				for(int i=0; i<8; i++){
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
					t.push_back(make_tuple(1, nx, ny));
				}	
			}			
		}
		
		while(!t.empty()){
			tr.push_front(t.front());
			t.pop_front();
		}
		
		// Winter
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				nut[j][i] += A[j][i];
			}
		}
	}
	
	cout << tr.size();
	
	return 0;
}