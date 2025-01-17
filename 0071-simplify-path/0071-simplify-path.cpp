class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') continue;
            string temp;

            while (i < path.size() && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if (temp == ".") continue;
            else if (temp == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(temp);
            }
        }

        if (st.empty()) return "/";
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};