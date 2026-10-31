class Solution {
    int count(int n, vector<int>& t) {
        if (n == 0 || n == 1)
            return 1;
        if (t[n] != -1)
            return t[n];
        return t[n] = count(n - 1, t) + count(n - 2, t);
    }

public:
    int climbStairs(int n) {
        vector<int>t(n+1,-1);

        return count(n,t);
    }
};