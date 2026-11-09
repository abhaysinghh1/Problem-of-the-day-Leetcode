class Solution {
    unordered_map<string,int>mpp;

    bool has_Dupli(string &s1,string &s2){
        int arr[26]={0};
        for(auto it:s1){
            if(arr[it-'a']>0){
                return true;
            }
            arr[it-'a']++;
        }
        for(auto it:s2){
            if(arr[it-'a']>0) return true;
        }
        return false;
    }
    int solve(int i,vector<string>&arr,string temp,int n){
        if(i>=n) return  temp.length();

        int inc=0;
        int exc=0;
if(mpp.find(temp)!=mpp.end()){
            return mpp[temp];
        }
        if(has_Dupli(arr[i],temp)){
            //agar dupli hai to nhi le sakte
            exc=solve(i+1,arr,temp,n);
        }
        else{
            inc=solve(i+1,arr,temp+arr[i],n);
            exc=solve(i+1,arr,temp,n);
        }
        return mpp[temp]=max(inc,exc);
    }
public:
    int maxLength(vector<string>& arr) {
        string temp="";
        mpp.clear();
         int n=arr.size();
         int i=0;
          return solve(i,arr,temp,n); 
    }
};