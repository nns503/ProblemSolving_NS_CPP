#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &limit, vector<vector<int>> &gogo){
    int answer = 0;
    vector<int> road(101, 0);
    vector<int> speed(101, 0);

    int prvLimit = 0;
    for(int i=0; i<limit.size(); i++){
        for(int j=0; j<limit[i][0]; j++){
            road[prvLimit + j] = limit[i][1];
        }
        prvLimit = prvLimit + limit[i][0]; 
    }

    int prvGogo = 0;
    for(int i=0; i<gogo.size(); i++){
        for(int j=0; j<gogo[i][0]; j++){
            speed[prvGogo + j] = gogo[i][1];
        }
        prvGogo = prvGogo + gogo[i][0]; 
    }

    for(int i=0; i<=100; i++){
        answer = max(answer, speed[i] - road[i]);
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> limit(n, vector<int>(2));
    vector<vector<int>> gogo(m, vector<int>(2));
    for(int i=0; i<n; i++){
        cin >> limit[i][0] >> limit[i][1];
    }
    for(int i=0; i<m; i++){
        cin >> gogo[i][0] >> gogo[i][1];
    }

    cout << solve(limit, gogo);

    return 0;
}