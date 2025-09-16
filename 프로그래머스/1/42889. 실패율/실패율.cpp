#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> remaining(N + 1);
    
    for (auto& p : stages) {
        remaining[p - 1]++;
    } // 1 3 2 1 0 1
    
    int passed = 0;
    vector<pair<long double, int>> fail(N);
    cout << '\n';
    for (int i = N; i >= 0; i--) {
        passed += remaining[i];
        if (i == N) continue;
        if(remaining[i] == 0 || passed == 0){
            fail[i] = {0, i};
            continue;
        }
        fail[i] = {(double)remaining[i] / passed, i};
        cout << fail[i].first << ' ' << fail[i].second << '\n';
    } // 0.125/0 0.444/1 0.5/2 0.5/3 0/4
    
    sort(fail.begin(), fail.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    });
    
    for (auto & f : fail) {
        answer.push_back(f.second + 1);
    }
    
    return answer;
}

//       1 2 3 4 5 6 7 8
//     1   *             1
//     2 *   *   *       3
//     3             * * 2
//     4           *     1
//     5                 0
//     6       *         1