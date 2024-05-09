class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> arr(nums.size());
        arr[0] = nums[0];
        for(int i=1; i<arr.size(); i++){
            arr[i] = max(nums[i], nums[i] + arr[i-1]);
        }

        
        return *max_element(arr.begin(), arr.end());
    }
};