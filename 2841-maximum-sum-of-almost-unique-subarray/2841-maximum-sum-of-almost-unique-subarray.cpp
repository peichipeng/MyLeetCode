class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long maxSum = 0;
        long long sum = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
            sum += nums[i];
        }
        if (freq.size() >= m) maxSum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];
            freq[nums[i]]++;
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0) {
                freq.erase(nums[i - k]);
            }
            if (freq.size() >= m) maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};