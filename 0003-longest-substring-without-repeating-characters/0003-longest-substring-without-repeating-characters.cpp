class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        unordered_set<char> set;
        int ans = 0;
        for (int end = 0; end < s.size(); end++) {
            while (set.find(s[end]) != set.end()) {
                set.erase(s[start]);
                start++;
            }
            set.insert(s[end]);
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};