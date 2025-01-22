class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string doubledString = s + s;

        return doubledString.find(goal) != string::npos;
    }
};