#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int q;
    cin >> str >> q;
    
    vector<vector<int>> arr(str.size(), vector<int>(26, 0));
    vector<int> sum(26, 0);

    for(int i=0; i<str.size(); i++){
        sum[str[i] - 'a']++;
        for(int j=0; j<26; j++) arr[i][j] = sum[j];
    }

    while(q--){
        char c;
        int l, r;
        cin >> c >> l >> r;
        if(l == 0) cout << arr[r][c - 'a'] << '\n';
        else cout << arr[r][c - 'a'] - arr[l-1][c - 'a'] << '\n';
    }
    return 0;
}