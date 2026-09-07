class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> uwords(words.begin(), words.end());
        vector<string> ans;

        for (string word : words) {
            int n = word.length();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;

            for (int si = 0; si < n; si++) {
                if (dp[si] != 1) continue;

                for (int ei = si; ei < n; ei++) {
                    // Don't allow the complete word itself
                    if (ei - si + 1 < n &&
                        uwords.count(word.substr(si, ei - si + 1))) {
                        dp[ei + 1] = 1;
                    }
                }
            }

            if (dp[n] == 1)
                ans.push_back(word);
        }

        return ans;
    }
};