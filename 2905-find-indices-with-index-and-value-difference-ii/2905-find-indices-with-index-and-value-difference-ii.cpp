class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mini = 0, maxi = 0, n = nums.size();
        for (int i = indexDifference; i < n; i++) {
            if (nums[i - indexDifference] < nums[mini]) mini = i - indexDifference;
            if (nums[i - indexDifference] > nums[maxi]) maxi = i - indexDifference;
            if (nums[i] - nums[mini] >= valueDifference) return {mini, i};
            if (nums[maxi] - nums[i] >= valueDifference) return {maxi, i};
        }
        return {-1, -1};
    }
};