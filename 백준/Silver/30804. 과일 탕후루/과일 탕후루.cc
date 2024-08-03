#include <bits/stdc++.h>

using namespace std;

int n;
int answer = -1;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> arr(n);
    vector<int> num(10, 0);

    for(auto &cur : arr){
        cin >> cur;
    }

    int cnt = 0;
    int en = 0;
    for(int st=0; st<n; st++){
        auto cur = arr[st];
        if(num[cur] == 0) cnt++;
        num[cur]++;
        while(cnt >= 3){
            int prv = arr[en];
            num[prv]--;
            if(num[prv] == 0) cnt--;
            en++;
        }
        answer = max(st - en + 1, answer);
    }

    cout << answer;

    return 0;
}