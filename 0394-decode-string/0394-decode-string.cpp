class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                string decodedString = "";
                while (st.top() != '[') {
                    decodedString += st.top();
                    st.pop();
                }
                // pop [ from stack
                st.pop();
                int base = 1;
                int k = 0;
                while (!st.empty() && isdigit(st.top())) {
                    k = k + (st.top() - '0') * base;
                    st.pop();
                    base *= 10;
                }
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        st.push(decodedString[j]);
                    }
                    k--;
                }
            } else {
                st.push(s[i]);
            }
        }
        string result;
        for (int i = st.size() - 1; i >= 0; i--) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};