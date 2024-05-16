class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer(numRows);

        for(int i=0; i<numRows; i++){
            vector<int> temp(i+1, 0);
            for(int j=0; j<i+1; j++){
                if(j == 0 || j == i) temp[j] = 1;
                else{
                    temp[j] = answer[i-1][j] + answer[i-1][j-1];
                }
            }
            answer[i] = (temp);
        }      

        return answer;
    }
};