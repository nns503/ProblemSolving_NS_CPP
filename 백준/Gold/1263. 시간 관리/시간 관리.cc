#include <bits/stdc++.h>

using namespace std;

struct work {
    int t;
    int s;
};

bool cmp(work w1, work w2){
    return w1.s > w2.s;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;
    vector<work> arr(n);

    for(int i=0; i<n; i++){
        int t, s;
        cin >> t >> s;
        arr[i] = {t, s};
    }

    sort(arr.begin(), arr.end(), cmp);

    int answer = 0x3f3f3f3f;

    for(auto cur : arr){
        if(answer > cur.s) answer = cur.s;
        answer -= cur.t;
        if(answer < 0) answer = -1;    
    }

    cout << answer;
    return 0;
}