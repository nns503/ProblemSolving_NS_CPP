#include <bits/stdc++.h>

using namespace std;

int sum[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, p;
    cin >> s >> p;
    vector<int> sum(p.size(), 0x3f3f3f3f);
    sum[0] = 1;

    for(int i=1; i<p.size(); i++){
        sum[i] = sum[i-1] + 1;
        for(int j=0; j<=i; j++){
            string str = p.substr(j, i-j+1);
            if(s.find(str) == string::npos) continue;
            if(j == 0){
                sum[i] = 1;
            }
            else sum[i] = min(sum[i], sum[j-1] + 1);
        }
    }

    cout << sum[p.size()-1];
}