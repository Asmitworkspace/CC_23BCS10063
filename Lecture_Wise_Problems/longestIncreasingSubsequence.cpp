class Solution {
public:
    int lowerBound(vector<int>& dp, int x) {
        int l = 0, r = dp.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (dp[mid] < x) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int x : nums) {
            int pos = lowerBound(dp, x);
            if (pos == dp.size()) dp.push_back(x);
            else dp[pos] = x;
        }
        return dp.size();
    }
};
