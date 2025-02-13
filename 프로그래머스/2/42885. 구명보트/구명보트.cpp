#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size();
    sort(people.begin(), people.end());
    int st = 0;
    int en = people.size() - 1;
    while(st < en){
        if(people[st] + people[en] <= limit){
            st++;
        }
        en--;
    }
    return answer - st;
}