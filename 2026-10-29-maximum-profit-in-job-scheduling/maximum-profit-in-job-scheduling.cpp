class Solution {
    int dp[50001];
    int n;
    //find the first job jiska starting point >=end of the first or the we can the current job
    int next_index(int i,vector<vector<int>>&v){
        int target=v[i][1];
        int l=i;
        int r=n-1;
        int res=n+1;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(v[mid][0]>=target){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return res;



    }
    int solve(vector<vector<int>>&v,int i){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        int next=next_index(i,v);
        int taken=v[i][2]+solve(v,next);
        int not_taken=solve(v,i+1);

        return dp[i]= max(taken,not_taken);
    }
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
         n=st.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({st[i],et[i],profit[i]});

        }

        auto comp=[&](auto & a,auto &b){
            return a[0]<b[0];
        };
        //sort according to start time
        sort(v.begin(),v.end(),comp);
        memset(dp,-1,sizeof(dp));

        return solve(v,0);

        
    }
};