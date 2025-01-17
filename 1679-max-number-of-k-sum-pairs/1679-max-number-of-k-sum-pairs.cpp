class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        int result = 0;
        while (start < end) {
            int sum = nums[start] + nums[end];
            if (sum < k) {
                start++;
            } else if (sum > k) {
                end--;
            } else {
                result++;
                start++;
                end--;
            }
        }
        return result;
    }
};