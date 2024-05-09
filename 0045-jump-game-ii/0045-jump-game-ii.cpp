class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int cnt = 0;
        while(cur < n-1){
            int len = nums[cur];
            int nxt = cur;
            
            for(int i=1; i<=len; i++){
                int temp = cur + i;
                if(temp > n-1) continue;
                else if(temp == n-1) return cnt+1;
                else{
                    if(nxt + nums[nxt] < temp + nums[temp]){
                        nxt = temp;
                    }
                }
            }

            cur = nxt;
            cnt++;
        }
        return cnt;
    }
};