class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int maxLength = 0;
        int sum = 0;
        prefix[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum += nums[i - 1];
            int num = sum - k;
            if (prefix.find(num) != prefix.end()) {
                maxLength = max(maxLength, i - prefix[num]);
            }
            if (prefix.find(sum) == prefix.end()) {
                prefix[sum] = i;
            }
        }
        return maxLength;
    }
};