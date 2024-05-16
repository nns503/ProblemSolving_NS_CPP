class Solution {
public:

    int solve(vector<int> &nums, int target, int p, int sum){
        if(p >= nums.size()){
            if(sum == target) return 1;
            return 0;
        }

        int answer = 0;
        answer += solve(nums, target, p+1, sum + nums[p]);
        answer += solve(nums, target, p+1, sum - nums[p]);

        return answer;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};