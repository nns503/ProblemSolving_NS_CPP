#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

int n,m;
int result=99999999;
vector<pair<int, int>> home;
vector<pair<int, int>> chiken;
int dist[100][2700];
int arr[105];
int vis[105];

int getDistance(int x1, int x2, int y1, int y2){
	return (abs(x1-x2)+abs(y1-y2));
}

void setDistance(){
	for(int i=0;i<home.size();i++){
		for(int j=0;j<chiken.size();j++){
			dist[i][j] = getDistance(home[i].X,chiken[j].X,home[i].Y,chiken[j].Y);
		}
	}
}

int getChikenDistance(){
	int sum = 0;
	int mindist[100];
	fill(mindist,mindist+home.size(),99999999);
	for(int i=0;i<home.size();i++){
		for(int j=0;j<m;j++){
			mindist[i] = min(dist[i][arr[j]],mindist[i]);
		}
	}
	for(int i=0;i<home.size();i++){
		sum += mindist[i];
	}	
	return sum;
}

void func(int cnt, int order){
	if(cnt==m){
		result = min(getChikenDistance(),result);
		return ;		
	}
	for(int i=order;i<chiken.size();i++){
		if(vis[i]==true) continue;
		vis[i] = true;
		arr[cnt] = i;
		func(cnt+1,i);
		vis[i] = false;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int y=0;y<n;y++){
		for(int x=0;x<n;x++){
			int data;
			cin >> data;
			if(data==1){
				home.push_back({y,x});
			} 
			else if(data==2){
				chiken.push_back({y,x});
			}
		}
	}
	
	setDistance();
	func(0,0);
	cout << result;
	
	return 0;
}