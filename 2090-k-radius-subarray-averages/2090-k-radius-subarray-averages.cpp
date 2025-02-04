class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> result(nums.size(), -1);
        int numCount = 2 * k + 1;
        long long sum = 0;
        if (nums.size() < numCount) return result;
        for (int i = 0; i <= 2 * k; i++) {
            sum += nums[i];
        }
        result[k] = sum / numCount;
        for (int i = 2 * k + 1; i < nums.size(); i++) {
            sum += nums[i] - nums[i - numCount];
            result[i - k] = sum / numCount;
        }
        return result;
    }
};