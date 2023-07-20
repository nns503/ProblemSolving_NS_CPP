#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
vector<int> AB;
vector<int> CD;
long long answer;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			AB.push_back(A[i]+B[j]);
			CD.push_back(C[i]+D[j]);
		}
	}
	
	sort(CD.begin(), CD.end());
	
	for(int i=0; i<AB.size(); i++){
		answer += upper_bound(CD.begin(), CD.end(), -AB[i]) - lower_bound(CD.begin(), CD.end(), -AB[i]);

	}
	

	cout << answer;
	return 0;
}