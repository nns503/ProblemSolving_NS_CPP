#include <bits/stdc++.h>
#define EN first
#define ST second

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;
    int n;
    cin >> n;
    vector<int> day(366, 0);

    for(int i=0; i<n; i++){
        int st, en;
        cin >> st >> en;
        
        for(int i=st; i<=en; i++){
            day[i]++;
        }
    }

    int st = 0;
    int mx = 0;

    for(int i=1; i<=365; i++){
        if(day[i] == 0){
            answer += (i - st) * mx;
            mx = 0;
            st = 0;
        }
        else{
            if(st == 0) st = i;
            mx = max(mx, day[i]);
        }
    }

    answer += (366 - st) * mx;
    cout << answer;
    return 0;
}