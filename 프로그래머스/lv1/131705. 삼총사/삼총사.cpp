#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    sort(number.begin(), number.end());
    for(int i = 0; i<number.size()-2; i++){
        for(int j = i+1; j < number.size()-1; j++){
            int target = -(number[i] + number[j]);
            auto a = equal_range(number.begin() + j + 1, number.end(), target);
            if(a.first != a.second){
                answer += a.second - a.first;
            }
            
        }
    }
    return answer;
}