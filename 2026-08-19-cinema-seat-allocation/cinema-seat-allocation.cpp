class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
         unordered_map<int,unordered_set<int>>mpp;
         for(auto &it:reservedSeats){
            int row=it[0];
            int seat=it[1];
            mpp[row].insert(seat);
         }
         int result=0;
         result+=(n-mpp.size())*2;

         for( auto &[row,booked]:mpp){

            auto  isAvailable=[&](int seat){
               return booked.find(seat)==booked.end(); 
            };

            bool grpA=isAvailable(2) && isAvailable(3) && isAvailable(4) &&isAvailable(5);
            bool grpB=isAvailable(4) && isAvailable(5) && isAvailable(6) &&isAvailable(7);
            bool grpC=isAvailable(6) && isAvailable(7) && isAvailable(8) &&isAvailable(9);
            if(grpA && grpC){
                result+=2;
            }
             else if(grpA|| grpB|| grpC){
                result+=1;
            }
           
         }
          return result;
        
    }
};