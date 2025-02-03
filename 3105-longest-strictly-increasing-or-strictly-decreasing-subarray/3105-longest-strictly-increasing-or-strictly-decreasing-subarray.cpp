class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
                result = max(count, result);
            } else {
                count = 1;
            }
        }
        count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
                result = max(count, result);
            } else {
                count = 1;
            }
        }
        return result;
    }
};