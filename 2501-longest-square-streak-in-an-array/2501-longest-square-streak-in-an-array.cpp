class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> arr;
        unordered_map<int, int> m;
        for(auto cur : nums) arr.insert(cur);
        for(auto cur : arr){
            int cnt = 1;
            int nxt = cur*cur;
            while(arr.find(nxt) != arr.end()){
                cnt++;
                arr.erase(nxt);
                if(nxt >= 1000) break;  
                nxt = nxt * nxt;
            }
            if(cnt == 1) m.insert({cur, -1});
            else m.insert({cur, cnt});
        }
        int answer = -1;
        for(auto cur : m){
            answer = max(answer, cur.second);
        }
        return answer;
    }
};