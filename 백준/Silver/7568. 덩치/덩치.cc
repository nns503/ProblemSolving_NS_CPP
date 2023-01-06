#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>	

using namespace std;


int main(void){
	int n;
	int a,b;
	vector<pair<int, int>> large;
	cin >> n;
	
	int ranking[51];	
	fill_n(ranking,51,1);
	for(int i=0;i<n;i++){
		cin >> a >> b;
		large.push_back(pair<int,int>(a,b));
	}
		
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(i==j) continue;
			if(large[i].first<large[j].first){
				if(large[i].second<large[j].second) ranking[i]++;
			}
			else if(large[i].first>large[j].first){
				if(large[i].second>large[j].second) ranking[j]++;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout << ranking[i] << " ";
	}	
	
	

}



