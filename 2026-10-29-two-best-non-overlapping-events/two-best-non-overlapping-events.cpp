class Solution {
    int dp[100001][2];
    int n;
    int next_index(int i,vector<vector<int>>& events,int end_index){
        int l=i;
        int r=n-1;
        int res=n+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>end_index){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;

    }
    int solve(int i,vector<vector<int>>& events ,int cnt){
        if(i>=n) return 0;
        if(cnt==2) return 0;
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        int next=next_index(i,events,events[i][1]);
        int taken=events[i][2]+solve(next,events,cnt+1);
        int not_taken=solve(i+1,events,cnt);

        return dp[i][cnt]= max(taken,not_taken);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        sort(events.begin(),events.end());
        memset(dp,-1,sizeof(dp));
  return solve(0,events,0);
        
    }
};