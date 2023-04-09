#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] == b[0]) return a[0] > b[0];
    return a[0] < b[0];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int e = -30001;
    sort(routes.begin(), routes.end(), cmp);
    for(int i = 0; i<routes.size() ;i++){
        if(e < routes[i][0]){
            e = routes[i][1];
            answer++;
        }
        else{
            if(e > routes[i][1]) e = routes[i][1];
        }
    }
    return answer;
}

