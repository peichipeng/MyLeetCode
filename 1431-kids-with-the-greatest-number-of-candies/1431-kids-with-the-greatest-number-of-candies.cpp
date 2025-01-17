class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxVal = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > maxVal) maxVal = candies[i];
        }
        vector<bool> result(candies.size(), false);
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] == maxVal || extraCandies + candies[i] >= maxVal) {
                result[i] = true;
            }
        }
        return result;
    }
};