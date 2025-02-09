class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            int val = i - nums[i];
            if (freq.find(val) != freq.end()) {
                count += freq[val];
            }
            freq[val]++;
        }
        long long totalPairs = ((nums.size() - 1) + 1) * (nums.size() - 1) / 2;
        return totalPairs - count;
    }
};