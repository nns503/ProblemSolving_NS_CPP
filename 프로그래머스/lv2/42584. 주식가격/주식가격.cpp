#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int>> s;
vector<int> solution(vector<int> prices) {
    vector<int> temp(100001);
    s.push({0, -1});
    for(int i = 0; i < prices.size(); i++){
       while(s.top().first > prices[i]){
           temp[s.top().second] = i - s.top().second;
           s.pop();
       }
        s.push({prices[i], i});
    }
    while(s.size() != 1){
        temp[s.top().second] = prices.size() - s.top().second - 1;
        s.pop();
    }
    vector<int> answer(temp.begin(), temp.begin() + prices.size());
    return answer;
}
