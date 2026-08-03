class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // dp[i] stores the max score the current player can get from index i to the end
        // Size n + 6 prevents out-of-bound errors when looking ahead up to i+6
        vector<int> dp(n + 6, 0); 

        // Fill the table from right to left (bottom-up)
        for (int i = n - 1; i >= 0; i--) {
            int take1 = INT_MIN;
            int take2 = INT_MIN;
            int take3 = INT_MIN;

            // --- Option 1: Current player takes 1 stone ---
            int bob_min_for_take1 = min({dp[i + 2], dp[i + 3], dp[i + 4]});
            take1 = stoneValue[i] + bob_min_for_take1;

            // --- Option 2: Current player takes 2 stones ---
            if (i + 1 < n) {
                int bob_min_for_take2 = min({dp[i + 3], dp[i + 4], dp[i + 5]});
                take2 = stoneValue[i] + stoneValue[i + 1] + bob_min_for_take2;
            }

            // --- Option 3: Current player takes 3 stones ---
            if (i + 2 < n) {
                int bob_min_for_take3 = min({dp[i + 4], dp[i + 5], dp[i + 6]});
                take3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + bob_min_for_take3;
            }

            // Store the best choice for the current player at position i
            dp[i] = max({take1, take2, take3});
        }

        // Calculate total stone values to find Bob's score
        int tsum = 0;
        for (int i = 0; i < n; i++) {
            tsum += stoneValue[i];
        }

        int alice_score = dp[0];
        int bob_score = tsum - alice_score;

        if (alice_score > bob_score) return "Alice";
        if (bob_score > alice_score) return "Bob";
        return "Tie";
    }
};
