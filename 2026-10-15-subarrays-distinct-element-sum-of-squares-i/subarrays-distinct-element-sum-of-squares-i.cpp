class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mpp;
            for(int j=i;j<n;j++){
                mpp[nums[j]]++;
                int s=mpp.size();
                ans+=(s*s);
            }
        }
        return ans;
        
    }
};