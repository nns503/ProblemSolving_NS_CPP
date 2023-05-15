#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n;
char board[7][7];
bool ty[7];
bool tx[7];
bool sy[7];
bool sx[7];
bool answer;
vector<pair<int, int>> th;
vector<pair<int, int>> p;
vector<int> arr;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= n || x >= n);
}

bool chk(){
	for(int i=0; i<th.size(); i++){
		for(int k=0; k<4; k++){
			auto cur = th[i];
			while(true){
				cur.Y += dy[k];
				cur.X += dx[k];
				if(OOB(cur.Y, cur.X)) break;
				if(board[cur.Y][cur.X] == 'O') break;
				if(board[cur.Y][cur.X] == 'S'){
					return false;
				}
			}
		}
	}

	return true;
}

int main(void){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
			if(board[i][j] == 'T'){
				th.push_back({i, j});
				ty[i] = true;
				tx[j] = true;
			}
			else if(board[i][j] == 'S'){
				sy[i] = true;
				sx[j] = true;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(board[i][j] != 'X') continue;
			if((ty[i] && sy[i]) || (tx[j] && sx[j])){
				p.push_back({i, j});
			}
		}
	}
	
	for(int i=0; i<p.size(); i++){
		if(i < 3) arr.push_back(0);
		else arr.push_back(1);
	}
	
	do{
		vector<pair<int, int>> a;
		for(int i=0; i<arr.size(); i++){
			if(arr[i] == 0){
				a.push_back({p[i].Y, p[i].X});
			}
		}
		
		for(int i=0; i<3; i++){
			board[a[i].Y][a[i].X] = 'O';
		}
		
		if(chk()){
			cout << "YES";
			return 0;
		}
		
		for(int i=0; i<3; i++){
			board[a[i].Y][a[i].X] = 'X';
		}
	}while(next_permutation(arr.begin(), arr.end()));
	
	cout << "NO";
	return 0;
}