class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();

        vector<vector<int>> board(m, vector<int>(n, 0));

        for(int x=0; x<n; x++){
            if(ob[0][x] == 1) break;
            else board[0][x] = 1;
        }

        for(int y=1; y<m; y++){
            if(ob[y][0] == 0) board[y][0] = board[y-1][0];
            for(int x=1; x<n; x++){
                if(ob[y][x] == 1) continue;
                board[y][x] = board[y-1][x] + board[y][x-1];
            }
        }

        return board[m-1][n-1];
    }
};