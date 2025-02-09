class Solution {
    void check(int num, unordered_map<int, int>& map, vector<int>& ans) {
        int k = INT_MAX;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0 && map.count(i)) {
                k = min(k, map[i]);
            }
            if (i != num / i && num % i == 0 && map.count(num / i)) {
                k = min(k, map[num/i]);
            }
        }
        if (k != INT_MAX) ans.push_back(k);
        else ans.push_back(-1);
    }
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int groupSize = groups.size();
        unordered_map<int, int> map;
        for (int i = 0; i < elements.size(); i++) {
            if (map.count(elements[i]) == 0) map[elements[i]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < groups.size(); i++) {
            check(groups[i], map, ans);
        }
        return ans;
    }
};