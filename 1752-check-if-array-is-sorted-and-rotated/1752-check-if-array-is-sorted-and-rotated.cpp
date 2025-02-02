class Solution {
public:
    bool check(vector<int>& nums) {
        bool foundRotationPoint = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (!foundRotationPoint) {
                    foundRotationPoint = true;
                } else return false;
            }
        }
        if (foundRotationPoint && nums[0] < nums[nums.size() - 1]) return false;
        return true;
    }
};