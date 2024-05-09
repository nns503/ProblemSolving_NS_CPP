class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> board(m, vector<int>(n, 0));

        for(int x=0; x<n; x++) board[0][x] = 1;

        for(int y=1; y<m; y++){
            board[y][0] = 1;
            for(int x=1; x<n; x++){
                board[y][x] = board[y][x-1] + board[y-1][x];
            }
        }

        return board[m-1][n-1];
    }
};