class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int size = nums.size();

        unordered_map<int, int> pairProductsFreq;

        int total = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                pairProductsFreq[nums[i] * nums[j]]++;
            }
        }

        for (auto [val, freq] : pairProductsFreq) {
            // The combination formula for choosing two pairs
            int pairsOfEqualProduct = (freq - 1) * freq / 2;

            total += pairsOfEqualProduct * 8;
        }
        return total;
    }
};