class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0;
        int cost = 0;
        int maxLength = 0;
        for (int end = 0; end < s.size(); end++) {
            cost += abs(s[end] - t[end]);
            while (cost > maxCost) {
                cost -= abs(s[start] - t[start]);
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};