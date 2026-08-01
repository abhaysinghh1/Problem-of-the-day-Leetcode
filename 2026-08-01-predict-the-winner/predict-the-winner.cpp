class Solution {

    int solve(vector<int>& nums,int i,int j){
        if((i-j)>0){
             return 0;
        }
        if(i==j) return nums[i];
       //take i;
       int take=nums[i]+min(solve(nums,i+1,j-1),solve(nums,i+2,j));

       int not_take=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));

  return max(take,not_take);
    }
public:
    bool predictTheWinner(vector<int>& nums) {

        int n=nums.size();
         int tsum=0;
         for(int i=0;i<n;i++){
            tsum+=nums[i];
         }

         int a=solve(nums,0,n-1);
         int b=tsum-a;
         return a>=b;
        
    }
};