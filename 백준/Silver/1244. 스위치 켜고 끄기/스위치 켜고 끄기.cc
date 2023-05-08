#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101];
int stu;



int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}	
	
	cin >> stu;
	
	while(stu--){
		int g, a;
		cin >> g >> a;	
		
		if(g == 1){
			for(int i = a; i<=n; i+=a){
				arr[i] = !arr[i];
			}
		}
		else if(g == 2){
			arr[a] = !arr[a];
			for(int i = 1; a+i <= n && a-i > 0; i++){
				if(arr[a+i] == arr[a-i]){
					arr[a+i] = !arr[a+i];
					arr[a-i] = !arr[a-i];
				}
				else break;
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		cout << arr[i] << ' ';
		if(i % 20 == 0) cout << '\n';
	}
	return 0;
}