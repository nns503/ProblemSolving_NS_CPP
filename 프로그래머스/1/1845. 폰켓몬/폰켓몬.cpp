#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for(auto cur : nums){
        s.insert(cur);
    }
    
    return min(s.size(), nums.size() / 2);
}