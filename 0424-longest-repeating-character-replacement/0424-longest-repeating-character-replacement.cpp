class Solution {
public:
    int characterReplacement(string s, int k) {
        int lo = 1;
        int hi = s.size() + 1;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;

            if (canMakeValidSubstring(s, mid, k)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
private:
    bool canMakeValidSubstring(string& s, int length, int k) {
        int record[26] = {0};
        int maxFrequency = 0;
        int start = 0;
        for (int end = 0; end < s.size(); end++) {
            record[s[end] - 'A'] += 1;

            // if the window exceeds length
            if (end + 1 - start > length) {
                record[s[start] - 'A'] -= 1;
                start++;
            }
            maxFrequency = max(record[s[end] - 'A'], maxFrequency);

            // return true if the window with the length is valid
            if (length - maxFrequency <= k) return true;
        }
        return false;
    }
};