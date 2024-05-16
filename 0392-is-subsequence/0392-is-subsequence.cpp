class Solution {
public:
    
    bool isSubsequence(string s, string t) {
        if(s == t) return true;
        int sIndex = 0;
        for(int i=0; i<t.size(); i++){
            if(s[sIndex] == t[i]) sIndex++; 
            if(sIndex >= s.size()) return true;
        }

        return false;
    }
};