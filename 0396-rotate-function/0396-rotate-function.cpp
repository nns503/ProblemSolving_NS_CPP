class Solution {
public:

    int maxRotateFunction(vector<int>& nums) {
        int all = 0;
        int sum = 0;
        int n = nums.size();
        for(auto cur : nums) all += cur;
        for(int i=0; i<n; i++){
            sum += (i * nums[i]);
        }

        int answer = sum;

        for(int m=n-1; m>=0; m--){
            sum += (all - nums[m] * n);
            answer = max(sum, answer);
            cout << answer << '\n';
        }

        return answer;
    }
};