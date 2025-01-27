class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums);
        for (int i = 0; i < nums.size(); i++) {
            int newIndex = (i + k) % nums.size();
            nums[newIndex] = ans[i];
        }
    }
};