class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=*min_element(begin(nums1),end(nums1));
        if(mini%2==1) return true;

        for(auto it:nums1){
            if(it%2==1) return false;
            // yahan par chack kar rahe jab mini even hai to array mein saare even hai kya
        }
        return true;
        
    }
};