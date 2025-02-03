#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}
string solution(vector<int> nums) {
    string answer = "";
    vector<string> numbers(nums.size());
    for(int i=0; i<nums.size(); i++){
        numbers[i] = to_string(nums[i]);
    }
    sort(numbers.begin(), numbers.end(), cmp);
    for(auto cur : numbers){
        answer += cur;
    }
    if(answer[0] == '0'){
        return "0";
    }
    return answer;
}