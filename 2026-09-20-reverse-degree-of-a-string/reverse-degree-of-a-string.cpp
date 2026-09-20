class Solution {
public:
    int reverseDegree(string s) {

        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int m='z'-s[i]+1;
            sum+=m*(i+1);
            
        }
        return sum;
    }
};