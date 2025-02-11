class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int, int> remainder;
        for (int num : time) {
            int complement = 60 - num % 60;
            if (num % 60 == 0) complement = 0;
            if (remainder.find(complement) != remainder.end()) {
                ans += remainder[complement];
            }
            remainder[num % 60]++;
        }
        return ans;
    }
};