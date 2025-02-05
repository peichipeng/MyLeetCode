class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> result(k);
        if (x <= arr[0]) {
            for (int i = 0; i < k; i++) {
                result[i] = arr[i];
            }
        } else if (x >= arr[n - 1]) {
            for (int i = n - k; i < n; i++) {
                result[i - n + k] = arr[i];
            }
        } else {
            int left = 0, right = n - 1;
            int index;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (arr[mid] == x) {
                    index = mid;
                    break;
                } else if (arr[mid] < x) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int leftPointer, rightPointer;
            if (left > right) {
                leftPointer = right, rightPointer = left;
            } else {
                leftPointer = index, rightPointer = index + 1;
            }
            for (int i = 0; i < k; i++) {
                int leftDiff = (leftPointer >= 0) ? x - arr[leftPointer] : -1;
                int rightDiff = rightPointer < arr.size() ? arr[rightPointer] - x : -1;
                if (leftPointer >= 0 && leftDiff <= rightDiff || rightPointer >= arr.size()) {
                    result[i] = arr[leftPointer];
                    leftPointer--;
                } else {
                    result[i] = arr[rightPointer];
                    rightPointer++;
                }
            }
            sort(result.begin(), result.end());
        }
        return result;
    }
};