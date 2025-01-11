class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (char chr: s) {
            if (result.empty() || result.back() != chr) {
                result.push_back(chr);
            } else {
                result.pop_back();
            }
        }
        return result;
    }
};