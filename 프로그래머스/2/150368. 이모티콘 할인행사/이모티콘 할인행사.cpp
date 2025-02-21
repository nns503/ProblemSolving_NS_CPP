#include <bits/stdc++.h>

using namespace std;

int d[4] = {10, 20, 30, 40};

void solve(int n, vector<int> &arr, vector<vector<int>> &users, vector<int> &emo, vector<int> &answer){
    if(n == emo.size()){
        int cnt = 0;
        int sumPrice = 0;
        for(int i=0; i<users.size(); i++){
            int per = users[i][0];
            int price = users[i][1];
            int sum = 0;
            for(int j=0; j<emo.size(); j++){
                if(per <= arr[j]){
                    sum += emo[j] / 100 * (100 - arr[j]);
                }
            }
            if(sum >= price) cnt++;
            else sumPrice += sum;
        }
        
        if(answer[0] < cnt){
            answer = {cnt, sumPrice};
        }
        else if(answer[0] == cnt){
            answer = {cnt, max(answer[1], sumPrice)};
        }
        return;
    }
    
    for(int i=0; i<4; i++){
        int temp = arr[n];
        arr[n] = d[i];
        solve(n+1, arr, users, emo, answer);
        arr[n] = temp;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer = {0, 0};
    vector<int> arr(emoticons.size(), 0);
    solve(0, arr, users, emoticons, answer);
    return answer;
}