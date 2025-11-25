#include <bits/stdc++.h>

using namespace std;

int convert(string strTime){
    int sum = 0;
    sum += stoi(strTime.substr(0, 2)) * 60;
    sum += stoi(strTime.substr(3, 2));
    
    return sum;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto cur : book_time){
        int startTime = convert(cur[0]);
        int endTime = convert(cur[1]) + 10;
    
        while(!pq.empty() && pq.top() <= startTime){
            pq.pop();
        }
        pq.push(endTime);
        
        answer = max(answer, (int)pq.size());
    }
    return answer;
}