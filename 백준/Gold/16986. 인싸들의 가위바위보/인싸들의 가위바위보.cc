#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[10][10];
bool jiu[11];
int kh[21];
int mh[21];
int mhw, khw, jiuw;
int mhg, khg;
bool chk;

void func(int opn, int cnt){
	if(jiuw == k){
		chk = true;
		return;
	}
	if(mhw == k || khw == k || cnt == 20){
		return;
	}
	if(opn == 5){ // 경희 vs 민호  
		if(arr[kh[khg]][mh[mhg]] == 2){
			khw++; mhg++; khg++;
			func(1, cnt+1);
			khw--; mhg--; khg--;
		}
		else{
			mhw++; mhg++; khg++;
			func(2, cnt+1);
			mhw--; mhg--; khg--;
		}
	}
	else{
		for(int cur = 1; cur<=n; cur++){
			if(jiu[cur] == false) continue;
			if(opn == 1){ // 지우 vs 경희  
				if(arr[cur][kh[khg]] == 2){
					jiu[cur] = false;
					jiuw++; khg++;
					func(2, cnt+1);
					jiu[cur] = true;
					jiuw--; khg--;
				}
				else{
					jiu[cur] = false;
					khw++; khg++;
					func(5, cnt+1);
					jiu[cur] = true;
					khw--; khg--;
				}
			}
			else if(opn == 2){ // 지우 vs 민호  
				if(arr[cur][mh[mhg]] == 2){
					jiu[cur] = false;
					jiuw++; mhg++;
					func(1, cnt+1);
					jiu[cur] = true;
					jiuw--; mhg--;
				}
				else{
					jiu[cur] = false;
					mhw++; mhg++;
					func(5, cnt+1);
					jiu[cur] = true;
					mhw--; mhg--;
				}
			}
		}
	}
}

int main(void){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cin >> arr[i][j];
	}
	
	for(int i=0; i<20; i++) cin >> kh[i];
	for(int i=0; i<20; i++) cin >> mh[i];
	fill(jiu, jiu + 11, true);
	func(1, 0);
	
	cout << chk;
	return 0;
}