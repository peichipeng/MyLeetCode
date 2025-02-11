class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> remainder;
        long long ans = 0;
        for (int hour : hours) {
            if (hour % 24 == 0) {
                ans += remainder[0];
                remainder[0]++;
            } else {
                ans += remainder[24 - hour % 24];
                remainder[hour % 24]++;
            }
        }
        return ans;
    }
};