#include <bits/stdc++.h>

using namespace std;


int solve(int n, string str){
    int answer = 0;

    int st = 0;
    int cnt = 0;
    unordered_map<char, int> alp;

    for(int en=0; en<str.size(); en++){
        auto cur = str[en];
        alp[cur]++;
        if(alp[cur] == 1) cnt++;

        while(cnt > n){
            int prv = str[st];
            alp[prv]--;
            if(alp[prv] == 0) cnt--;
            st++;
        }
        answer = max(answer, en+1 - st);
    }

    return answer;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;

    cin >> n >> str;

    cout << solve(n, str);
    return 0;
}