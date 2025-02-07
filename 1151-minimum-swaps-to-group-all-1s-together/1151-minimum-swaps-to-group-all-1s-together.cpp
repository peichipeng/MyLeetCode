class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOnes = 0;
        for (int i = 0; i < data.size(); i++) {
            totalOnes += data[i];
        }
        if (totalOnes <= 1) return 0;
        int maxOnesInGroup = 0;
        int oneCount = 0;
        for (int i = 0; i < totalOnes; i++) {
            oneCount += data[i];
        }
        maxOnesInGroup = oneCount;
        for (int i = totalOnes; i < data.size(); i++) {
            oneCount += data[i] - data[i - totalOnes];
            maxOnesInGroup = max(oneCount, maxOnesInGroup);
        }
        return totalOnes - maxOnesInGroup;
    }
};