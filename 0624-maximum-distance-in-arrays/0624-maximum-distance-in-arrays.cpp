class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDistance = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0][arrays[0].size() - 1];
        for (int i = 1; i < arrays.size(); i++) {
            int n = arrays[i].size();
            
            int minDiff = max(abs(maxVal - arrays[i][0]), abs(minVal - arrays[i][0]));
            int maxDiff = max(abs(maxVal - arrays[i][n - 1]), abs(minVal - arrays[i][n - 1]));
            maxDistance = max(maxDistance, max(minDiff, maxDiff));

            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i][n - 1]);
        }
        return maxDistance;
    }
};