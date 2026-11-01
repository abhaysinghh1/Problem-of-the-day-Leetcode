class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int left=0;
        int right=n-1;
        int sum=skill[0]+skill[n-1];
        long long ans=0;
        while(left<n/2){
             if(skill[left]+skill[right]==sum){
                ans+=skill[left]*skill[right];
                right--;
             }
             else{
                return -1;
             }
             left++;
        }
        return ans;
        
    }
};