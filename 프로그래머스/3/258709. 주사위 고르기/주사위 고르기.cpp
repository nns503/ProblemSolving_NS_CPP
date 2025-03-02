#include <bits/stdc++.h>

using namespace std;

int maxNum = 0;
vector<int> ans;

void sumNum(int sum, int index, vector<int> &t, vector<int> &sumList, vector<vector<int>> &dice){
    if(index == t.size()){
        sumList.push_back(sum);
        return ;
    }
    int mx = 0;
    for(int i=0; i<6; i++){
        sumNum(sum + dice[t[index]][i], index+1, t, sumList, dice);
    }
}

void findAnswer(vector<int> &t1, vector<int> &t2, vector<vector<int>> &dice){
    vector<int> oneList;
    vector<int> twoList;
    sumNum(0, 0, t1, oneList, dice);
    sumNum(0, 0, t2, twoList, dice);
    int cnt = 0;
    for(auto a : oneList){
        for(auto b : twoList){
            if(a > b) cnt++;
        }
    }
    if(maxNum < cnt){
        maxNum = cnt;
        vector<int> newArr;
        for(auto num : t1){
            newArr.push_back(num+1);
        }
        ans = newArr;
    }
}

void solve(vector<bool> &arr, int st, int k, vector<vector<int>> &dice){
    if(dice.size() / 2 == k){   
        vector<int> team1;
        vector<int> team2;
        for(int i=0; i<dice.size(); i++){
            if(arr[i]) team1.push_back(i);
            else team2.push_back(i);
        }
        findAnswer(team1, team2, dice);
        return;
    }
    for(int i=st; i<dice.size(); i++){
        arr[i] = true;
        solve(arr, i+1, k+1, dice);
        arr[i] = false;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<bool> arr(dice.size(), false);
    solve(arr, 0, 0, dice);
    return ans;
}