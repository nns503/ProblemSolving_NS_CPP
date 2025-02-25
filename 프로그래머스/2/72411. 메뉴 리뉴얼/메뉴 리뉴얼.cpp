#include <bits/stdc++.h>
#define A first
#define B second

using namespace std;

map<vector<char>, int> m;

void solve(int index, string str, vector<char> &arr){
    if(str.size() == index){
        return ;
    }
    
    for(int i=index; i<str.size(); i++){
        arr.push_back(str[i]);
        m[arr]++;
        solve(i+1, str, arr);
        arr.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        vector<char> arr;        
        solve(0, orders[i], arr);
    }
    vector<int> maxNum(11, 0);
    for(auto cur : m){
        maxNum[cur.A.size()] = max(maxNum[cur.A.size()], cur.B);
    }
    
    for(auto cur : m){
        int len = cur.A.size();
        for(int i=0; i<course.size(); i++){
            if(len == course[i]){
                if(maxNum[len] >= 2 && maxNum[len] == cur.B){
                    string str = "";
                    for(auto x : cur.A){
                        str += x;
                    }
                    answer.push_back(str);
                    break;
                }
            }
        }
    }
    return answer;
}