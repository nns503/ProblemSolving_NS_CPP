#include <bits/stdc++.h>

using namespace std;

int n, m;
long long answer;
vector<long long> card;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        card.push_back(a);
    }

    while(m--){
        sort(card.begin(), card.end());
        long long sum = card[0] + card[1];
        card[0] = sum;
        card[1] = sum;
    }

    for(auto cur : card){
        answer += cur;
    }

    cout << answer;
    return 0;
}