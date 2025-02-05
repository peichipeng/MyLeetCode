class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            int letter = s[left];
            if (s[right] != s[left]) break;
            while (left <= right && s[left] == letter) left++;
            while (left <= right && s[right] == letter) right--;
        }
        return right - left + 1;
    }
};