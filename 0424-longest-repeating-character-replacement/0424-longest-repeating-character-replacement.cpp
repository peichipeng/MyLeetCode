class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> allLetters;

        for (int i = 0; i < s.size(); i++) {
            allLetters.insert(s[i]);
        }

        int maxLength = 0;
        for (char letter: allLetters) {
            int start = 0;
            int count = 0;

            for (int end = 0; end < s.size(); end++) {
                if (s[end] == letter) {
                    count++;
                }
                while (!isWindowValid(start, end, count, k)) {
                    if (s[start] == letter) {
                        count--;
                    }
                    start++;
                }
                maxLength = max(end + 1 - start, maxLength);
            }
        }
        return maxLength;
    }
private:
    bool isWindowValid(int start, int end, int count, int k) {
        return end + 1 - start - count <= k;
    }
};