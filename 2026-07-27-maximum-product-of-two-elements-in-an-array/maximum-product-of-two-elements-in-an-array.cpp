class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi1=(nums[n-1]-1)*(nums[n-2]-1);
        int maxi2=(nums[0]-1)*(nums[1]-1);
        return max(maxi1,maxi2);
    }
};