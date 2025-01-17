class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                int tmp0 = asteroids[i];
                while (tmp0 < 0) {
                    if (st.empty() || st.top() < 0) {
                        st.push(tmp0);
                        break;
                    }
                    int tmp1 = st.top();
                    if (abs(tmp0) < tmp1) {
                        break;
                    } else if (abs(tmp0) > tmp1) {
                        st.pop();
                    } else {
                        st.pop();
                        break;
                    }
                }
            }
        }
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};