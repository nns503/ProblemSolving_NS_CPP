#include <bits/stdc++.h>

using namespace std;

int n, k, m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;

    int cur = -1;
    deque<int> dq;
    vector<int> ans;
    for(int i=1; i<=n; i++) dq.push_back(i);

    while(!dq.empty()){
        int stk = 1;
        int cur;
        if((ans.size() / m) % 2 == 0){
            cur = dq.front();
            while(stk < k){
                dq.push_back(cur);
                dq.pop_front(); 
                cur = dq.front(); 
                stk++;              
            }
            dq.pop_front();
        }
        else{
            cur = dq.back();
            while(stk < k){
                 dq.push_front(cur);
                 dq.pop_back(); 
                cur = dq.back();  
                stk++;
            }
            dq.pop_back();
        }
        ans.push_back(cur);
    }

    for(auto cur : ans) cout << cur << '\n';
    return 0;
}