/*
There is an m by n grid with a ball. 
Given the start coordinate (i,j) of the ball, 
you can move the ball to adjacent cell or cross the grid boundary in four directions 
(up, down, left, right). However, you can at most move N times. 

Find out the number of paths to move the ball out of grid boundary. 
The answer may be very large, return it after mod 109 + 7.

Example 1:

Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
/*

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        for (int k = 1; k <= N; ++k) {
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    long long v1 = (x == 0) ? 1 : dp[k - 1][x - 1][y];
                    long long v2 = (x == m - 1) ? 1 : dp[k - 1][x + 1][y];
                    long long v3 = (y == 0) ? 1 : dp[k - 1][x][y - 1];
                    long long v4 = (y == n - 1) ? 1 : dp[k - 1][x][y + 1];
                    dp[k][x][y] = (v1 + v2 + v3 + v4) % 1000000007;
                }
            }
        } 
        return dp[N][i][j];
    }
};
*/
