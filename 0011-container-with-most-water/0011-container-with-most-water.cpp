class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int answer = 0;
        int l = 0;
        int r = n-1;

        while(l < r){
            int left = height[l];
            int right = height[r];
            int sum = min(left, right) * (r - l);
            answer = max(sum, answer);
            if(left > right) r--;
            else l++;
        }
        return answer;
    }
};