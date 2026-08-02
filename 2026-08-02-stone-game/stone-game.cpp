class Solution {
    int t[501][501];
    int solve(vector<int>&piles,int i,int j){
        if(i>j) return 0;
        if(i==j) return piles[i];

       if(t[i][j]!=-1) return t[i][j];


        //take i;
        int take=piles[i]+min(solve(piles,i+2,j),solve(piles,i+1,j-1));
        //not take i

        int not_take=piles[j]+min(solve(piles,i,j-2),solve(piles,i+1,j-1));

        return t[i][j]=max(take,not_take);

    }
public:
    bool stoneGame(vector<int>& piles) {

        int n=piles.size();
 memset(t,-1,sizeof(t));
        int tsum=0;
        for(int i=0;i<n;i++){
            tsum+=piles[i];
        }
        int a=solve(piles,0,n-1);
        int b=tsum-a;

        return a>b;
        
    }
};