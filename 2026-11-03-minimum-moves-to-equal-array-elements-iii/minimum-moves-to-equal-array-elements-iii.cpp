class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        int maxi=nums[n-1];
        for(auto it:nums){
            ans+=(maxi-it);
        }
        return ans;
        
    }
};