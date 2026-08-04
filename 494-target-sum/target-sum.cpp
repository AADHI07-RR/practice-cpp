class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> curr;
        curr.push_back(0);

        for (int i = 0; i < nums.size(); i++) {
            vector<int> next(curr.size() * 2);
            int si = 0;

            for (int val : curr) {
                next[si++] = val + nums[i];
                next[si++] = val - nums[i];
            }

            curr = next;
        }

        int ans = 0;
        for (int val : curr)
            if (val == target)
                ans++;

        return ans;
    }
};