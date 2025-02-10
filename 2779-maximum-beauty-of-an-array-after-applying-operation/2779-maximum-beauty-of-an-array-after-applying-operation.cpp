class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int preNum = nums[0] + k;
        int maxLength = 0;
        for (int end = 0; end < nums.size(); end++) {
            while (nums[end] - k > preNum) {
                start++;
                preNum = nums[start] + k;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};