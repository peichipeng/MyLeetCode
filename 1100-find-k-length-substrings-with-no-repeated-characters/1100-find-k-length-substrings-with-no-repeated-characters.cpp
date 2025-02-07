class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int result = 0;
        if (s.size() < k) return result;
        unordered_map<char, int> map;
        for (int i = 0; i < k; i++) {
            map[s[i]]++;
        }
        if (map.size() == k) result++;
        for (int i = k; i < s.size(); i++) {
            map[s[i]]++;
            if (--map[s[i - k]] == 0) {
                map.erase(s[i - k]);
            }
            if (map.size() == k) result++;
        }
        return result;
    }
};