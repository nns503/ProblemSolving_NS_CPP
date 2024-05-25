class Solution {
public:

    static bool cmp(string a, string b){
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        string answer;
        for(auto cur : nums){
            if(cur == 0) continue;
            arr.push_back(to_string(cur));
        }
        sort(arr.begin(), arr.end(), cmp);
        for(auto cur : arr){
            answer.append(cur);
        }
        if(answer.empty()) answer = "0";    
        return answer;
    }
};