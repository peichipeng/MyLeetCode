class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSum = -1;
        int record[10] = {0};
        
        for (int num : nums) {
            int val = num;
            int largestDigit = 0;
            while (val != 0) {
                largestDigit = max(largestDigit, val % 10);
                val /= 10;
            }
            int prevNum = record[largestDigit];
            if (prevNum != 0) maxSum = max(maxSum, prevNum + num);
            record[largestDigit] = max(prevNum, num);
        }
        return maxSum;
    }
};