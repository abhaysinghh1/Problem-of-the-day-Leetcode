class Solution {
public:
    int minimumPushes(string word) {
       int n=word.size();
       map<char,int>mpp;
       for(auto it:word){
        mpp[it]++;
       }
       vector<std::pair<char, int>> vec(mpp.begin(), mpp.end());
       sort(vec.begin(),vec.end(),[](auto a,auto b){
        return a.second>b.second;
       });
      
        int len=vec.size();
       int ans=0;
       for(int i=0;i<len;i++){
        int cost=(i/8 ) +1;
        ans+=cost*vec[i].second;
       }
return ans;
    }
};