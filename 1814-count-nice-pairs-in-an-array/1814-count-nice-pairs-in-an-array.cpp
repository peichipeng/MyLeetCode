class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1000000007;
        long long ans = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            int reverseNum = 0;
            int tmp = num;
            while (tmp > 0) {
                reverseNum = 10 * reverseNum + tmp % 10;
                tmp /= 10;
            }
            int current = num - reverseNum;
            ans += freq[current];
            freq[current]++;
        }
        return ans % MOD;
    }
};