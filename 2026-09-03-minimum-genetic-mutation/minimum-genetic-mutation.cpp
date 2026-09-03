class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());

        unordered_set<string> visited;
        queue<string> q;
        int level = 0;
        q.push(startGene);
        visited.insert(startGene);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();

                if (curr == endGene)
                    return level;

                for (auto ch : "ACGT") {
                    // yahan par chack kar rahe hai saare choices ke saath
                    for (int i = 0; i < curr.size(); i++) {
                        //yahan par sabhi indexes par chars ko daalkar dekh rahen hai
                        string next=curr;
                        next[i] = ch;

                        if (visited.find(next) == visited.end() &&
                            bankset.find(next) != bankset.end()) {
                                //yahan par chack kar rahen hai ki kahin visted to nhi hai jo string hamne abhi banayi hai
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};