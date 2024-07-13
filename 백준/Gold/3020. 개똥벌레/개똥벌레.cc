#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n >> h;

    vector<int> f;
    vector<int> s;
    vector<int> answer(n+1, 0);
    vector<int> dp(h+1, 0);

    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(i % 2){
            s.push_back(a);
        }
        else{
            f.push_back(a);
        }
    }

    sort(f.begin(), f.end());
    sort(s.begin(), s.end(), greater<int>());

    int fi = 0;
    int si = 0;
    dp[0] = f.size(); 

    for(int i=1; i<=h; i++){
        dp[i] = dp[i-1];
        while(fi < f.size() && f[fi] < i){
            fi++;
            dp[i]--;
        }

        while(si < s.size() && h - s[si] < i){
            si++;
            dp[i]++;
        }
    }

    sort(dp.begin()+1, dp.end());

    int cnt = 1;    
    for(int i=2; i<=h; i++){
        if(dp[i-1] != dp[i]) break;
        cnt++;        
    }

    cout << dp[1] << ' ' << cnt;

    
    return 0;
}