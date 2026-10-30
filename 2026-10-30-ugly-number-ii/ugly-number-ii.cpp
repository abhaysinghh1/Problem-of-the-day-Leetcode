class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n + 1);
        // intially
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;

        res[1] = 1;
        for (int i = 2; i <= n; i++) {
            int i2_ugly_number = res[i2] * 2;
            int i3_ugly_number = res[i3] * 3;
            int i5_ugly_number = res[i5] * 5;

            int mini = min({i2_ugly_number, i3_ugly_number, i5_ugly_number});
            res[i] = mini;

            if (mini == i2_ugly_number) {
                i2++;
            }  if (mini == i3_ugly_number) {
                i3++;
            } if(mini==i5_ugly_number) {
                i5++;
            }
        }
        

            return res[n];
    }
};