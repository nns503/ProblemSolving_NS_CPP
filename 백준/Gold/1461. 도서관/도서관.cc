#include <bits/stdc++.h>

using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> plus;
    vector<int> minus;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a < 0){
            minus.push_back(abs(a));
        }
        else if(a > 0) plus.push_back(a);
    }
    
    sort(minus.begin(), minus.end(), greater<>());
    sort(plus.begin(), plus.end(), greater<>());
    
    int answer = 0;
    for(int i=0; i<minus.size(); i += m){
        answer += minus[i] * 2;
    }
    for(int i=0; i<plus.size(); i += m){
        answer += plus[i] * 2;
    }
    int temp = 0;
    if(minus.size() > 0) temp = max(minus[0], temp);
    if(plus.size() > 0) temp = max(plus[0], temp);

    cout << answer - temp;
}