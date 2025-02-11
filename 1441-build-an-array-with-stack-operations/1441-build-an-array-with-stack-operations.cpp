class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int index = 0;
        for (int i = 1; i <= n; i++) {
            result.push_back("Push");
            if (target[index] == i) {
                index++;
                if (index == target.size()) break;
            } else {
                result.push_back("Pop");
            }
        }
        return result;
    }
};