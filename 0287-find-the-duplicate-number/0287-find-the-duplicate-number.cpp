class Solution {
public:
    int store(vector<int>& nums, int cur) {
        if (nums[cur] == cur) return cur;
        int next = nums[cur];
        nums[cur] = cur;
        return store(nums, next);
    }
    int findDuplicate(vector<int>& nums) {
        return store(nums, 0);
    }
};