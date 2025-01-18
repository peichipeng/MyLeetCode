class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxBananas = max(piles[i], maxBananas);
        }
        int left = 1;
        int right = maxBananas;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hour = 0;
            for (int i = 0; i < piles.size(); i++) {
                hour += piles[i] / mid + (piles[i] % mid != 0);
            }
            if (hour > h) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};