class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;
        for (int i = 0; i < spells.size(); i++) {
            int left = 0, right = potions.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long product = (long long)spells[i] * potions[mid];
                if (product < success) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            result.push_back(potions.size() - left); 
        }
        return result;
    }
};