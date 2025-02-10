class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int minOps = INT_MAX;
        int sum = 0;
        int end = 0;
        while (sum < x && end < nums.size()) {
            sum += nums[end];
            end++;
        }
        if (sum < x) return -1;
        if (sum == x) minOps = min(minOps, end);
        sum = 0;
        end = nums.size() - 1;
        while (sum < x && end >= 0) {
            sum += nums[end];
            end--;
        }
        if (sum == x) minOps = min(minOps, int(nums.size()) - end - 1);
        end++;
        sum = 0;
        for (int start = end; start < nums.size(); start++) {
            while (sum < x) {
                sum += nums[end % nums.size()];
                end++;
            }
            if (sum == x) minOps = min(minOps, end - start);
            sum -= nums[start];
        }
        return minOps == INT_MAX ? -1 : minOps;
    }
};