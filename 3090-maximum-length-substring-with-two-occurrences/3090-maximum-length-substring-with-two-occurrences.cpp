class Solution {
public:
    int maximumLengthSubstring(string s) {
        int start = 0;
        unordered_map<char, int> freq;
        int maxLength = 0;
        for (int end = 0; end < s.size(); end++) {
            freq[s[end]]++;
            while (freq[s[end]] > 2) {
                freq[s[start]]--;
                start++;
            }
            maxLength = max(end - start + 1, maxLength);
        }
        return maxLength;
    }
};