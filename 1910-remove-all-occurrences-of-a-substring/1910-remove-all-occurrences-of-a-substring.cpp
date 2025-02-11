class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int strLength = s.size();
        int partLength = part.size();

        for (int index = 0; index < strLength; index++) {
            st.push(s[index]);

            if (st.size() >= partLength && checkMatch(st, part, partLength)) {
                for (int j = 0; j < partLength; j++) {
                    st.pop();
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
private:
    bool checkMatch(stack<char>& st, string& part, int partLength) {
        stack<char> temp = st;

        for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) {
            if (temp.top() != part[partIndex]) return false;
            temp.pop();
        }
        return true;
    }
};