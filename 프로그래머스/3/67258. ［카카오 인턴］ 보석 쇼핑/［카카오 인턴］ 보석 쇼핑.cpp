#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    answer[0] = 0;
    answer[1] = 1000000;
    int cnt = 0;
    set<string> s;
    for(auto str : gems) s.insert(str);
    int st = 0;
    map<string, int> m;
    for(int en=0; en<gems.size(); en++){
        auto cur = gems[en];
        m[cur]++;
        if(m[cur] == 1) cnt++;
        while(cnt == s.size()){
            auto x = gems[st];
            m[x]--;
            if(m[x] == 0){
                cnt--;
                if(en - st < answer[1] - answer[0]){
                    answer[0] = st + 1;
                    answer[1] = en + 1;
                }
            }
            st++;
        }
    }
    
    return answer;
}