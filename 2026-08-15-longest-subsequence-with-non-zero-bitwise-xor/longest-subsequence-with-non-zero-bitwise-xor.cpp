class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int n=nums.size();
       int allzero=true;
       int allxor=0;
       for(int i=0;i<n;i++){
   allxor^=nums[i];
   if(nums[i]!=0){
    allzero=false;
   }
       } 
       if(allzero) return 0;
       if(allxor==0) return n-1;
       return n;
    }
};