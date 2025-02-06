class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0) return result;
        if (k > 0) {
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum += code[i];
            }
            for (int i = k; i < n + k; i++) {
                sum += code[i % n] - code[i - k];
                result[i - k] = sum;
            }
        } else {
            int sum = 0;
            for (int i = n + k; i < n; i++) {
                sum += code[i];
            }
            result[0] = sum;
            for (int i = 1; i < n; i++) {
                int preIndex = i + k - 1;
                if (preIndex < 0) preIndex = n + preIndex;
                sum += code[i - 1] - code[preIndex];
                result[i] = sum;
            }
        }
        return result;
    }
};