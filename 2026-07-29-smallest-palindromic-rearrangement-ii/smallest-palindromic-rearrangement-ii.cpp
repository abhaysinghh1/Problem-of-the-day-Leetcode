class Solution {
    typedef long long ll;

    ll nCr(int n, int r, int k) {
        ll ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= k)
                return k;
        }
        return ans;
    }

    ll way(int h_len, vector<int> count, int k) {
        ll ans = 1;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                ans *= nCr(h_len, count[i], k);
                h_len -= count[i];
            }
            if (k <= ans) {
                break;
            }
        }
        return ans;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        char mid = '\0';

        
        vector<int> count(26, 0);
        string h_ans = "";
        int h_len = n / 2;
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
         for (int i = 0; i < 26; i++) {
            if (count[i] % 2)
                mid = 'a' + i;
        }
        for (int i = 0; i < 26; i++) {
            count[i] /= 2;
        }
       
        if (k > way(h_len, count, k))
            return "";
        ll ways = 1;
        for (int i = 0; i < h_len; i++) {
            for (int j = 0; j < 26; j++) {

                if (count[j] > 0) {
                    count[j] -= 1;
                    ways = way(h_len - i - 1, count, k);

                    if (k > ways) {
                        k -= ways;
                        count[j]++;
                    } else {
                        h_ans.push_back(j + 'a');
                        break;
                    }
                }
            }
        }
        string reverse_str = h_ans;
        reverse(reverse_str.begin(), reverse_str.end());
        if (n % 2 == 1) {
            return h_ans + mid + reverse_str;
        }
        return h_ans + reverse_str;
    }
};