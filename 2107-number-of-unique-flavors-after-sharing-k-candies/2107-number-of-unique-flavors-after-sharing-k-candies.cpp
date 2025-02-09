class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        if (candies.size() == 0) return 0;
        unordered_map<int, int> freq;
        for (auto candy : candies) {
            freq[candy]++;
        }
        int maxFlavors = -1;
        for (int i = 0; i < candies.size(); i++) {
            freq[candies[i]]--;
            if (freq[candies[i]] == 0) {
                freq.erase(candies[i]);
            }
            if (i - k >= 0) {
                freq[candies[i - k]]++;
            }
            if (i + 1 >= k) {
                maxFlavors = max(int(freq.size()), maxFlavors);
            }
        }
        return maxFlavors;
    }
};