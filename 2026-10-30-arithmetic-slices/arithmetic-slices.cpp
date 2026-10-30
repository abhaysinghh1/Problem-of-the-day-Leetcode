class Solution {
    int dp[5001];
    int solve(int i,vector<int>&nums){
        // jab length hi 3 se kam ho
        if(i<2) return 0;
        if(dp[i]!=-1) return dp[i];
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
            return  dp[i]=1+solve(i-1,nums);
        }
        return  dp[i]= 0;

    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        memset(dp,-1,sizeof(dp));

        for(int i=2;i<n;i++){
            cnt+=solve(i,nums);

        }

         return cnt;
    }
};