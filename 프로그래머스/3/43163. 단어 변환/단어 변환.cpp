#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int solution(string stWord, string enWord, vector<string> arr) {
    queue<pair<string, int>> q;
    q.push({stWord, 0});
    int cnt = 0;
    int n = arr.size();
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<n; i++){
            string nxtWord = arr[i];
            cnt = 0;
            for(int j=0; j<stWord.size(); j++){
                if(cur.X[j] != nxtWord[j]) cnt++;
                if(cnt >= 2) break;
            }
            if(cnt == 1){
                if(nxtWord == enWord) return cur.Y+1;
                swap(arr[i], arr[n-1]);
                n--; i--;
                q.push({nxtWord, cur.Y+1});
            }
        } 
    }
    return 0;
}