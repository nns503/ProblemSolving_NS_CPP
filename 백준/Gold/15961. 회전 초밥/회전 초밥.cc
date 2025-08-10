#include <bits/stdc++.h>

using namespace std;

int n, d, k, c;

int solve(vector<int> &arr){
    int answer = -1;
    vector<int> chobob(d+1, 0);
    chobob[c] = 0x3f3f3f3f;
    int cnt = 1; 

    int st = 0;
    for(int i=0; i<n+k; i++){
        if(i - st + 1 > k){
            int prv = arr[st % n];
            chobob[prv]--;
            if(chobob[prv] == 0){
                cnt--;
            }
            st++;
        }

        int number = arr[i % n];
        chobob[number]++;

        if(chobob[number] == 1){
            cnt++;
        }
        answer = max(answer, cnt);
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    vector<int> arr(n);
    for(auto &cur : arr) cin >> cur;

    cout << solve(arr);

    return 0;
}