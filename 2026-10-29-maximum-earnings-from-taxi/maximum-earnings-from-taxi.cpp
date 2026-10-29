class Solution {
    typedef long long ll;
    ll dp[100001];
    int k;
    int next_index(int i,vector<vector<int>>& rides,int end_index){
        int l=i;
        int r=k-1;
        int res=k+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(rides[mid][0]>=end_index){
                res=mid;
                r=mid-1;

            }
            else{
                l=mid+1;
            }
        }
        return res;

    }
    ll solve(int i,vector<vector<int>>& rides){
        if(i>=k) return 0;
        if(dp[i]!=-1) return dp[i];
        ll next=next_index(i,rides,rides[i][1]);
        ll taken=(rides[i][1]-rides[i][0])+rides[i][2]+solve(next,rides);
        ll not_taken=solve(i+1,rides);
        return  dp[i]=max(taken,not_taken);
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
         k=rides.size();
        sort(rides.begin(),rides.end());
        memset(dp,-1,sizeof(dp));

         return solve(0,rides);
        
    }
};