#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

char board[1001][1001];
int n;
pair<int, int> h;
pair<int, int> st;
int la, ra, ll, rl, w;

void getH(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(board[i][j] == '*'){
				h = {i+1, j};
				return ;
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> board[i][j];
		}
	}

	getH();
	
	for(int i=h.X-1; i>=1; i--){
		if(board[h.Y][i] == '*') la++;
		else break;
	}
	
	for(int i=h.X+1; i<=n; i++){
		if(board[h.Y][i] == '*') ra++;
		else break;
	}
	
	for(int i=h.Y+1; i<=n; i++){
		if(board[i][h.X] == '*'){
			st = {i, h.X};
			w++;
		}
		else break;

	}

	for(int i=st.Y+1; i<=n; i++){
		if(board[i][st.X-1] == '*') ll++;
		else break;
	}
	
	for(int i=st.Y+1; i<=n; i++){
		if(board[i][st.X+1] == '*') rl++;
		else break;
	}
	
	
	
	
	cout << h.Y << ' ' << h.X << '\n';
	cout << la << ' ' << ra << ' ' << w << ' ' << ll << ' ' << rl;
	
	
	return 0;
}