class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i = 0; i < k; i++) {
            count[nums[i]]++;
        }
        vector<int> result;
        result.push_back(count.size());
        for (int i = k; i < nums.size(); i++) {
            count[nums[i]]++;
            count[nums[i - k]]--;
            if (count[nums[i - k]] == 0) {
                count.erase(nums[i - k]);
            }
            result.push_back(count.size());
        }
        return result;
    }
};