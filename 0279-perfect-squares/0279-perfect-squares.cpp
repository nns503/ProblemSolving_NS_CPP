class Solution {
public:
    int numSquares(int n) {
        vector<int> arr;
        vector<int> dp(n+1, -1);
        queue<int> q;
        int t = 1;
        
        while(t*t <= n){
            arr.push_back(t*t);
            t++; 
        }

        q.push(0); 
        dp[0] = 0;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(auto sum : arr){
                int temp = cur + sum;
                if(temp > n) break;
                if(temp == n) return dp[cur] + 1;
                if(dp[temp] != -1) continue;
                dp[temp] = dp[cur] + 1;
                q.push(temp);
            }
        }
        return dp[n];
    }
};