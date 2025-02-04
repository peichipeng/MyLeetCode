class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int result = 0;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if ((sum / k) >= threshold) result++;
        for (int i = k; i < arr.size(); i++) {
            sum += arr[i];
            sum -= arr[i - k];
            if (sum / k >= threshold) result++;
        }
        return result;
    }
};