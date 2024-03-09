#include <bits/stdc++.h>

using namespace std;

int n;
int port[40001];
vector<int> len;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> port[i];
    }

    len.push_back(port[1]);

    for(int i=2; i<=n; i++){
        int cur = port[i];
        if(len.back() < cur) len.push_back(cur);
        else{
            len[lower_bound(len.begin(), len.end(), cur) - len.begin()] = cur;
        }
    }

    cout << len.size();
    return 0;
}
