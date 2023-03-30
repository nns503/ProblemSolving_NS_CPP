#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> num;
    sort(tangerine.begin(), tangerine.end());
    int cnt = 1;
    for(int i=1; i<tangerine.size(); i++){
        if(tangerine[i-1] == tangerine[i]) cnt++;
        else{
            num.push_back(cnt);
            cnt = 1;
        }
    }
    num.push_back(cnt);
    sort(num.begin(), num.end(), greater<int>());
    int sum = 0;
    for(int i=0; sum < k; i++){
        sum += num[i];
        answer++;
    }
    return answer;
}