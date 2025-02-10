class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int start = 0;
        int maxLength = 1;
        int repetitiveCount = 0;
        for (int end = 1; end < s.size(); end++) {
            repetitiveCount += (s[end] == s[end - 1]);
            while (repetitiveCount > 1) {
                repetitiveCount -= (s[start] == s[start + 1]);
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};