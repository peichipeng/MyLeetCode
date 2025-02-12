class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int maxa = 0, maxab = 0;
        for (int a : nums) {
            res = max(res, 1LL * maxab * a);
            maxab = max(maxa - a, maxab);
            maxa = max(a, maxa);
        }
        return res;
    }
};