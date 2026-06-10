#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> dp(m + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = dp[j - 1] + 1;
                ans = max(ans, dp[j]);
            } else {
                dp[j] = 0;
            }
        }
    }

    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstring(s1, s2) << endl;

    return 0;
}
