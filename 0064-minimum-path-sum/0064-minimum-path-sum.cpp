class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> board(n, vector<int>(m, 0));

        board[0][0] = grid[0][0];

        for(int x=1; x<m; x++){
            board[0][x] = board[0][x-1] + grid[0][x];
        }

        for(int y=1; y<n; y++){
            board[y][0] = grid[y][0] + board[y-1][0];
            for(int x=1; x<m; x++){
                board[y][x] = min(board[y-1][x], board[y][x-1]) + grid[y][x];
            }
        }

        return board[n-1][m-1];
    }
};