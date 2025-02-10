class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start = 0;
        int maxScore = 0;
        unordered_map<int, int> freq;
        int sum = 0;
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            freq[nums[end]]++;
            while (freq[nums[end]] > 1) {
                freq[nums[start]]--;
                sum -= nums[start];
                start++;
            }
            maxScore = max(maxScore, sum);
        }
        return maxScore;
    }
};