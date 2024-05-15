class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        
        vector<unordered_map<int, int>> m(n);
        int answer = 2;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int dif = nums[i] - nums[j];
                m[i][dif] = (m[j][dif] == 0) ? 2 : m[j][dif] + 1;  
                answer = max(answer, m[i][dif]);
            }
        }
        return answer;
    }
};
