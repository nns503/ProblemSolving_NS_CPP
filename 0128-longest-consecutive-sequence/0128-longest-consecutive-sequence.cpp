class Solution {
public:

    int find(int x, unordered_map<int, int> &p){
        if(p[x] == x) return x;
        return p[x] = find(p[x], p);
    }

    int uni(int u, int v, unordered_map<int, int> &p, unordered_map<int, int> &cnt){
        u = find(u, p);
        v = find(v, p);
        if(u == v) return u;
        if(cnt[u] > cnt[v]){
            p[v] = u;
            cnt[u] += cnt[v];
            return u;
        }
        p[u] = v;
        cnt[v] += cnt[u];
        return v; 
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> p;
        unordered_map<int, int> cnt;
        int answer = 0;

        for(auto &cur : nums){
            if(p.find(cur) != p.end()) continue;
            bool chkM = (p.find(cur-1) != p.end());
            bool chkP = (p.find(cur+1) != p.end());
            if(chkM && chkP){
                int num = uni(cur+1, cur-1, p, cnt);
                p[cur] = num;
                cnt[num]++;
                answer = max(cnt[num], answer);
            }
            else{
                p[cur] = cur;
                cnt[cur]++;
                int num = cur;
                if(chkM){
                    num = uni(cur, cur-1,p , cnt);
                }
                else if(chkP){
                    num = uni(cur, cur+1, p ,cnt);
                }
                answer = max(cnt[num], answer);
            }
        }

        return answer;
    }
};

/*

0 0 1 2 3 4 5 6 7 8
*/