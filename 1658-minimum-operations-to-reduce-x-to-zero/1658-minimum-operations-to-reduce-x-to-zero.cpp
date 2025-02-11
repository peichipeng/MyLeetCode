class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        int n = nums.size();
        int maxLength = -1;
        int left = 0;
        int currentSum = 0;

        for (int right = 0; right < n; right++) {
            currentSum += nums[right];

            while (currentSum > total - x && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            if (currentSum == total - x) {
                maxLength = max(right - left + 1, maxLength);
            }
        }
        return maxLength != -1 ? n - maxLength : -1;
    }
};