class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxVal = -1;
        unordered_map<int, int> map;
        for (int num : nums) {
            int val = num;
            int digitsSum = 0;
            while (val > 0) {
                digitsSum += val % 10;
                val /= 10;
            }
            if (map.find(digitsSum) != map.end()) {
                maxVal = max(maxVal, num + map[digitsSum]);
            }
            map[digitsSum] = max(map[digitsSum], num);
        }
        return maxVal;
    }
};