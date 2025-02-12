class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxVal = -1;
        unordered_map<int, int> map;
        for (int num : nums) {
            int val = num;
            int digitSum = 0;
            while (val > 0) {
                digitSum += val % 10;
                val /= 10;
            }
            if (map.find(digitSum) != map.end()) {
                maxVal = max(maxVal, num + map[digitSum]);
            }
            map[digitSum] = max(map[digitSum], num);
        }
        return maxVal;
    }
};