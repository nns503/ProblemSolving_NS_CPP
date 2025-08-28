#include <bits/stdc++.h>

using namespace std;

int solve(vector<string> &arr){
    string target = arr[0];
    map<char, int> m;
    for(char c : target){
        m[c]++; 
    }

    int answer = 0;
    for(int i=1; i<arr.size(); i++){
        string str = arr[i];
        int cnt = 0;
        map<char, int> compareMap;
        for(char c : str){
            compareMap[c]++;
        }

        for(char c='A'; c<='Z'; c++){
            cnt += abs(m[c] - compareMap[c]);
        }

        if(target.size() == str.size()){
            if(cnt <= 2) answer++;
        }
        else{
            if(cnt <= 1) answer++;
        }
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    vector<string> arr(n);
    for(auto &cur : arr){
        cin >> cur;
    }

    cout << solve(arr);

    return 0;
}