#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    while(n--){
        unordered_map<long long, int> m;
        int t;
        cin >> t;
        int mx = -1;
        long long mxNum = 0;
        for(int i=0; i<t; i++){
            long long num;
            cin >> num;
            m[num]++;
            if(m[num] > mx){
                mx = m[num];
                mxNum = num;
            }
        }
        if(mx > t/2) cout << mxNum << '\n';
        else cout << "SYJKGW\n";

    }
    return 0;
}