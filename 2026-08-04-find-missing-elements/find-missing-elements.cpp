class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mpp;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);

        }
        for(int i=mini;i<=maxi;i++){
            if(mpp[i]!=1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};