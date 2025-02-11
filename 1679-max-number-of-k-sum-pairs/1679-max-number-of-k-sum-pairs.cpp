class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        int ans = 0;
        for (int num : nums) {
            if (record[k - num] > 0) {
                record[k - num]--;
                ans++;
            } else {
                record[num]++;
            }
        }
        return ans;
    }
};