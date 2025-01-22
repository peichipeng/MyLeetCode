class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, vector<int>> freq1;
        unordered_map<char, vector<int>> freq2;
        for (int i = 0; i < s.size(); i++) {
            freq1[s[i]].push_back(i);
        }
        for (int i = 0; i < t.size(); i++) {
            freq2[t[i]].push_back(i);
        }
        set<vector<int>> set1;
        set<vector<int>> set2;
        for (auto& pair : freq1) {
            if (pair.second.size() > 1) set1.insert(pair.second);
        }
        for (auto& pair : freq2) {
            if (pair.second.size() > 1) set2.insert(pair.second);
        }
        return set1 == set2;
    }
};