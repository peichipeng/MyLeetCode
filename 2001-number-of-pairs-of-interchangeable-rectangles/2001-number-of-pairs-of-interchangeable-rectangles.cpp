class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long count = 0;
        unordered_map<double, int> freq;
        for (int i = 0; i < rectangles.size(); i++) {
            double ratio = (double)rectangles[i][0] / rectangles[i][1];
            count += freq[ratio];
            freq[ratio]++;
        }
        return count;
    }
};