class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> arr;
        arr.reserve(3);
        arr.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(nums[i] > arr.back()){
                arr.push_back(nums[i]);
                if(arr.size() == 3) return true;
            }
            else{
                for(int j=0; j<arr.size(); j++){
                    if(arr[j] >= nums[i]){
                        arr[j] = nums[i];
                        break;
                    }
                }
            }
            
        }
        return false;
    }
};