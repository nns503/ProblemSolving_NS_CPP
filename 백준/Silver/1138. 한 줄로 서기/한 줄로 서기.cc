#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> answer;    
    vector<int> num(n+1);
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=1; i<=n; i++){
        cin >> num[i];
        if(num[i] == 0) q.push(i);
    }

    while(!q.empty()){
        auto cur = q.top(); q.pop();
        answer.push_back(cur);
        for(int i=cur-1; i>=1; i--){
            num[i]--;
            if(num[i] == 0) q.push(i);
        }
    }

    for(auto cur : answer) cout << cur << ' ';

}