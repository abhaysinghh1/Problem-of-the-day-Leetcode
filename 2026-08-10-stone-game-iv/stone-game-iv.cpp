    class Solution {
        
        bool solve(int n,vector<int>&t){
            if(n==0) return false;
    if(t[n]!=-1){
        return t[n];
    }
            for(int k=1;k*k<=n;k++){
                if(solve(n-k*k,t)==false) {
                    t[n]=1;
                    return true;
                }
            }
        t[n]=0;
        return false;
        }
    public:
        bool winnerSquareGame(int n) {
            vector<int >t(n+1,-1);
            return solve(n,t);
            
        }
    };