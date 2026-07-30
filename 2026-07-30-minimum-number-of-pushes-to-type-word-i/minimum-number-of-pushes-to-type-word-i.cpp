class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        int div=n/8;
        int rem=n%8;
    int i=1;
        while(i<=div){
            ans+=8*i;
            i++;

        }
        ans+=rem*(div+1);
        return ans;
    }
};