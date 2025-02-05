class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxPoints = 0;
        int curPoints = 0;
        int n = cardPoints.size();
        for (int i = n - k; i < n;i++) {
            curPoints += cardPoints[i];
        }
        maxPoints = curPoints;
        for (int i = n; i < n + k; i++) {
            curPoints += cardPoints[i % n];
            curPoints -= cardPoints[(i - k) % n];
            maxPoints = max(curPoints, maxPoints);
        }
        return maxPoints;
    }
};