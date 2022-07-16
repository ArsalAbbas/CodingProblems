class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = { -1, 1, 0, 0};
    int dp[55][55][55];
    long long M = 1e9 + 7;

    bool isOut(int m, int n, int x, int y) {
        return (x < 0 or x == m or y == n or y < 0 );
    }
    int solve(int m, int n, int moves, int sr, int sc) {
        // Out check
        if (isOut(m, n, sr, sc)) return 1;

        // moves finish
        if (moves == 0) return 0;

        // if already calculated
        if (dp[sr][sc][moves] != -1) return dp[sr][sc][moves];

        long long ways = 0;
        // try every possibilities
        for (int i = 0; i < 4; i++) {
            int xx = sr + dx[i];
            int yy = sc + dy[i];

            ways += solve(m, n, moves - 1, xx, yy) % M;
            ways %= M;
        }

        dp[sr][sc][moves] = ways % M;
        return ways;
    }
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        // intialize dp with -1;
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, sr, sc);
    }
};