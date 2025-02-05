class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long curSum = 0;
        long long maxSum = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            curSum += nums[i];
            freq[nums[i]]++;
        }
        if (freq.size() == k) maxSum = curSum;
        for (int i = k; i < nums.size(); i++) {
            curSum += nums[i] - nums[i - k];
            freq[nums[i]]++;
            if (--freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            if (freq.size() == k) maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};