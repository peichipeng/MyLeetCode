class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> occurence;
        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            if (occurence.find(cards[i]) != occurence.end()) {
                ans = min(ans, i - occurence[cards[i]] + 1);
            }
            occurence[cards[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};