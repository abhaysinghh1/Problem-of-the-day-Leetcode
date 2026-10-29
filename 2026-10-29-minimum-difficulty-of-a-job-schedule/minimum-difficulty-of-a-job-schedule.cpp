class Solution {
    int dp[301][11];
    int solve(int ind,vector<int>& jobDifficulty, int d,int n){
        if(d==1){
            return *max_element(jobDifficulty.begin()+ind,jobDifficulty.end());
        }
        if(dp[ind][d]!=-1) return dp[ind][d];
 int maxi=jobDifficulty[ind];
 int final_result=INT_MAX;
        for(int i=ind;i<=n-d;i++){
             maxi=max(maxi,jobDifficulty[i]);
            int res=maxi+solve(i+1,jobDifficulty,d-1,n);
            final_result=min(final_result,res);
        }
        return dp[ind][d]=final_result;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        int sum=accumulate(jobDifficulty.begin(),jobDifficulty.end(),0);
        if(n==d) return sum;
        memset(dp,-1,sizeof(dp));
         int ans=solve(0,jobDifficulty,d,n);
         return ans;

    }
};