class Solution {
    int solve(int n){
        int sum=0;
        int prod=1;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            prod*=rem;
            n/=10;
        }
        return sum+prod;
    }
public:
    bool checkDivisibility(int n) {
        int div=solve(n);
        if(n%div==0) return true;
        return false;
        
    }
};