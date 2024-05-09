class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        while(cur <= n-1){
            int nxt = cur;
            int len = nums[cur];

            for(int i=0; i<=len; i++){
                int temp = cur + i;
                if(temp >= n-1) return true;
                else{
                    if(nxt + nums[nxt] < temp + nums[temp]){
                        nxt = temp;
                    }
                }
            }

            if(cur == nxt) return false;
            cur = nxt;
        }
        return false;
    }
};