class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       int index1 = -1;
       int index2 = -1;
       for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (index1 == -1) {
                index1 = i;
            } else if (index2 == -1) {
                index2 = i;
            } else {
                return false;
            }
        }
       }
       if (index1 == index2) return true;
       if (index1 == -1 || index2 == -1) return false;
       return s1[index1] == s2[index2] && s1[index2] == s2[index1];
    }
};