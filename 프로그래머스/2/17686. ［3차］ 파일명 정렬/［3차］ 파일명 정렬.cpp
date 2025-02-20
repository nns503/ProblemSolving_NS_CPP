#include <bits/stdc++.h>

using namespace std;

tuple<string, int, int> getTuple(string a, int index){
    for(auto &cur : a){
        cur = tolower(cur);
    }

    string aHead;
    int aNum = 0;
    int p = 0;
        
    for(int i=0; i<a.size(); i++){
        if(a[i] < '0' || a[i] > '9') continue;
        aHead = a.substr(0, i);
        p = i;
        break;
    }
    aNum = stoi(a.substr(p));
    return {aHead, aNum, index};
}

bool cmp(tuple<string, int, int> a, tuple<string, int, int> b){
    string a1, b1;
    int a2, a3, b2, b3;
    tie(a1, a2, a3) = a;
    tie(b1, b2, b3) = b;
    if(a1 == b1){
        if(a2 == b2){
            return a3 < b3;
        }
        return a2 < b2;
    }
    return a1 < b1;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string, int, int>> arr;
    for(int i=0; i<files.size(); i++){
        auto cur = getTuple(files[i], i);
        arr.push_back(cur);
    }
    
    sort(arr.begin(), arr.end(), cmp);
    for(auto cur : arr){
        string str;
        int num, index;
        tie(str, num, index) = cur;
        answer.push_back(files[index]);
    }
    
    return answer;
}