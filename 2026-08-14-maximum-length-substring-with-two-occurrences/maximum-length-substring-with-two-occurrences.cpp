class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int i=0;
        int j=0;
        int ans=INT_MIN;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            
                while(mpp[s[j]]>2){
                    mpp[s[i]]--;
                    i++;
                }
            
            ans=max(ans,j-i+1);
        }
        return ans;

    }
};