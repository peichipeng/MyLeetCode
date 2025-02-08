class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int operations = 0;
        long prefixSum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            if (num < 0) {
                pq.push(num);
            }
            prefixSum += num;
            while (prefixSum < 0) {
                prefixSum -= pq.top();
                pq.pop();
                operations++;
            }
        }
        return operations;
    }
};