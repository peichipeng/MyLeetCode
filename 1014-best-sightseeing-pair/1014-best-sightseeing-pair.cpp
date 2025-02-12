class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxPair = values[0];
        int ans = 0;
        for (int i = 1; i < values.size(); i++) {
            int current = values[i] - i;
            ans = max(ans, maxPair + current);
            maxPair = max(maxPair, values[i] + i);
        }
        return ans;
    }
};