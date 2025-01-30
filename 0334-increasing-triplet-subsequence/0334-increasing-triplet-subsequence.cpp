class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstNum = INT_MAX, secondNum = INT_MAX;
        for (int n : nums) {
            if (n <= firstNum) {
                firstNum = n;
            } else if (n <= secondNum) {
                secondNum = n;
            } else {
                return true;
            }
        }
        return false;
    }
};