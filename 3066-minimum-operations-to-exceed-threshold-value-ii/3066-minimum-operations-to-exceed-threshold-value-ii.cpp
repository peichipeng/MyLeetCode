class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int num : nums) {
            pq.push(num);
        }

        int ans = 0;
        while (pq.top() < k) {
            long long firstNum = pq.top();
            pq.pop();
            long long secondNum = pq.top();
            pq.pop();
            pq.push(min(firstNum, secondNum) * 2 + max(firstNum, secondNum));
            ans++;
        }
        return ans;
    }
};