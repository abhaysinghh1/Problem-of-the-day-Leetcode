class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
       for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
       } 
       int i=1;
       while(i<=100){
        if(mpp.find(k*i)!=mpp.end()){
            i++;
        }
        else{
            break;
        }
       }
       return k*i;
    }
};