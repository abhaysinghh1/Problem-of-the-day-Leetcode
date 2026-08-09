class Solution {
    int n;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(vector<int>& piles, int m, int i) {
        if (i >= n)
            return 0;

        if (dp[i][m] != -1)
            return dp[i][m];

        int ans = 0;

        // Can take all remaining piles
        if (i + 2 * m >= n)
            return dp[i][m] = suffix[i];

        for (int x = 1; x <= 2 * m; x++) {
            int opponent = solve(piles, max(m, x), i + x);

            // Current player takes 'x' piles.
            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][m] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(piles, 1, 0);
    }
};