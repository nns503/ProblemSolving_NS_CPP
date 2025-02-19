#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> arr;
    
    int st = 2;
    for(int i=st; i<s.size(); i++){
        auto c = s[i];
        if(c == '}' && st < i){
            arr.push_back(s.substr(st, i - st));
            st = i + 3;
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    
    vector<bool> chk(100001, false);
    
    for(auto cur : arr){
        int p = 0;
        int num;
        for(int i=0; i<=cur.size(); i++){
            if(i == cur.size()){
                num = stoi(cur.substr(p, i - p));
                break;
            }
            if(cur[i] == ','){
                num = stoi(cur.substr(p, i - p));
                if(chk[num] == false) break;
                p = i+1;
            }
        }
        chk[num] = true;
        answer.push_back(num);
    }
    
    return answer;
}