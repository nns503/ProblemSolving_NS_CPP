#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_first(pair<int, int> a, pair<int, int> b) {

	return a.first < b.first;
}

bool compare_second(pair<int, int> a, pair<int, int> b) {

	return a.second < b.second;
}

int main(void){
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		v.push_back(make_pair(a,i));
	}
	
	sort(v.begin(),v.end(),compare_first);
	
	int rank=0;
	vector<pair<int, int>> r;
	r.push_back(make_pair(0,v[0].second));
	for(int i=1;i<n;i++){
		if(v[i].first>v[i-1].first) rank++;
		r.push_back(make_pair(rank,v[i].second)); 
	}
	
	sort(r.begin(),r.end(),compare_second);
	
	for(int i=0;i<n;i++){
		cout << r[i].first << " ";
	}
	return 0;
}